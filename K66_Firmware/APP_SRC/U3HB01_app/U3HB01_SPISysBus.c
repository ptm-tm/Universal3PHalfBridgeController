// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2017.03.15
// 10:12:45
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"

LWSEM_STRUCT         sysb_sem;

extern const T_SPI_modules spi_mods[3];
extern       T_SPI_cbls    spi_cbl[3];

#define  SYSBUS_RXEND   BIT(1)  // ���� ������������ �� ISR �� ��������� ������ �� SPI

static T_DMA_SPI_cbl DS_cbl;
static uint32_t      g_en_dma;
/*------------------------------------------------------------------------------
  ���������� ���������� �� ������ DMA �� ���������� ������ ������ �� SPI 

 \param user_isr_ptr
 ------------------------------------------------------------------------------*/
static void DMA_SPI_SYSBUS_rx_isr(void *user_isr_ptr)
{
  DMA_MemMapPtr    DMA     = DMA_BASE_PTR;

  DMA->INT = BIT(DMA_SYSB_FM_CH); // ���������� ���� ����������  ������

  // ������� FIFO ��������� � �����������
  spi_mods[SYSB_SPI].spi->MCR  |= BIT(CLR_RXF) + BIT(CLR_TXF);
  // ������� ��� ����� � SPI
  spi_mods[SYSB_SPI].spi->SR =  spi_mods[SYSB_SPI].spi->SR;

  _lwevent_set(&spi_cbl[SYSB_SPI].spi_event, SYSBUS_RXEND); // ���������� �� ��������� ��������� �� DMA �� SPI � ������
}

/*------------------------------------------------------------------------------
  ���������������� 2-� ������� DMA �� ����� � �� �������� ��� ������ � ������� SPI
 ------------------------------------------------------------------------------*/
void Init_SYSBUS_SPI_DMA(void)
{
  T_DMA_SPI_RX_config rx_cfg;
  T_DMA_SPI_TX_config tx_cfg;

  tx_cfg.ch       = DMA_SYSB_MF_CH;                           // ����� ������ DMA
  tx_cfg.spi_pushr = (uint32_t)&(spi_mods[SYSB_SPI].spi->PUSHR); // ����� �������� PUSHR SPI
  tx_cfg.DMAMUX   = DMA_SYSB_DMUX_PTR;                        // ��������� �� ������������� ������� �������� ��� DMA
  tx_cfg.dmux_src = DMA_SYSB_DMUX_TX_SRC;                     // ����� ����� ��������� ��� ���������� �������������� DMAMUX ��� �������� �� DMA.
  tx_cfg.minor_tranf_sz = DMA_4BYTE_MINOR_TRANSFER;
  Config_DMA_for_SPI_TX(&tx_cfg, &DS_cbl);


  rx_cfg.ch        = DMA_SYSB_FM_CH;                          // ����� ������ DMA
  rx_cfg.spi_popr  = (uint32_t)&(spi_mods[SYSB_SPI].spi->POPR); // ����� �������� POPR SPI
  rx_cfg.DMAMUX    = DMA_SYSB_DMUX_PTR;                       // ����� ����� ��������� ��� ���������� �������������� DMAMUX ��� �������� �� DMA.
  rx_cfg.dmux_src  = DMA_SYSB_DMUX_RX_SRC;
  rx_cfg.minor_tranf_sz = DMA_4BYTE_MINOR_TRANSFER;
  Config_DMA_for_SPI_RX(&rx_cfg, &DS_cbl);

  Install_and_enable_isr(DMA_SYSB_RX_INT_NUM, spi_mods[SYSB_SPI].prio, DMA_SPI_SYSBUS_rx_isr); // ���������� �� ���������� ������ �� DMA
}



/*-----------------------------------------------------------------------------------------------------
  ������������� SPI ���������� ��� ��������� ���� ����������� ������� DRV8305, ����� ��������� � ����. � �����������������
  ��� �������� ��� ������������� DMA
 
 \param en_dma - ���� 1 �� ������������ DMA ��� ������  
 
 \return _mqx_uint 
-----------------------------------------------------------------------------------------------------*/
_mqx_uint SPISysBus_init(uint32_t en_dma)
{
  _mqx_uint res;

  g_en_dma = en_dma;
  if (g_en_dma == 0)
  {
    SPI_master_init(SYSB_SPI, SPI_16_BITS, 0, 1, SPI_BAUD_4MHZ, 1);
    res = _lwsem_create(&sysb_sem, 1);
    return res;
  }
  else
  {

    SPI_master_init(SYSB_SPI, SPI_16_BITS, 0, 1, SPI_BAUD_4MHZ, 0); // ��������� ������� SPI > 4 ��� �������� � ������������� ������ � ������� ��������� ������������ ������� �������
    Init_SYSBUS_SPI_DMA();
    res = _lwsem_create(&sysb_sem, 1);
    return res;
  }

}


/*-------------------------------------------------------------------------------------------------------------
  ����� ������ �� SPI � �������������� DMA
 
  sz - ���������� ���������� ����
  wbuff - ����� � ������������� �������
  rbuff - ����� � ������������ �������
 
  ������ ����� ������������ ��� ������������� DMA 
-------------------------------------------------------------------------------------------------------------*/
_mqx_uint SPISysBus_write_read_buf_dma(void *wbuff,  void *rbuff, uint32_t sz)
{
  _mqx_uint res = MQX_OK;
  int       i;

  Start_DMA_for_SPI_RXTX(&DS_cbl, wbuff, rbuff, sz);
  // ������� ����� ��������� �������� ������ �� DMA
  if (_lwevent_wait_ticks(&spi_cbl[SYSB_SPI].spi_event, SYSBUS_RXEND, FALSE, 10) != MQX_OK)
  {
    spi_cbl[SYSB_SPI].tx_err_cnt++;
    res = MQX_ERROR;
  }
  return res;
}




/*-----------------------------------------------------------------------------------------------------
 
 \param cmdw 
 \param pval 
 
 \return _mqx_uint 
-----------------------------------------------------------------------------------------------------*/
_mqx_uint SPISysBus_read_16bit_word(uint32_t cs, uint16_t outv, uint16_t *pinv)
{
  _mqx_uint res;
  if (g_en_dma == 0)
  {
    _lwsem_wait(&sysb_sem);
    SPI_push_16bit_word(SYSB_SPI, cs, outv);
    res = SPI_wait_tx_complete(SYSB_SPI, pinv, 10);
    _lwsem_post(&sysb_sem);
  }
  else
  {
    uint32_t w = cs | (uint32_t)outv;
    uint32_t v;
    _lwsem_wait(&sysb_sem);
    res = SPISysBus_write_read_buf_dma(&w, &v, 1);
    _lwsem_post(&sysb_sem);
    *pinv = v;
  }
  return res;
}

/*-----------------------------------------------------------------------------------------------------
 
 \param cmdw 
 \param val 
 
 \return _mqx_uint 
-----------------------------------------------------------------------------------------------------*/
_mqx_uint SPISysBus_write_16bit_word(uint32_t cs, uint16_t val)
{
  _mqx_uint res;
  if (g_en_dma == 0)
  {
    _lwsem_wait(&sysb_sem);
    SPI_push_16bit_word(SYSB_SPI, cs, val);
    res = SPI_wait_tx_complete(SYSB_SPI, 0, 10);
    _lwsem_post(&sysb_sem);
  }
  else
  {
    uint32_t w = cs | (uint32_t)val;
    uint32_t v;
    _lwsem_wait(&sysb_sem);
    res = SPISysBus_write_read_buf_dma(&w, &v, 1);
    _lwsem_post(&sysb_sem);
  }
  return res;
}

