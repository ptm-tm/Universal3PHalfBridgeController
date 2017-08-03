#include "App.h"
#include "freemaster.h"
#include "freemaster_os.h"

/*

������ ��������� FreeMaster



������ ������ ������ ���������� � Scope

 [2b] - ������ ������
 [04] - ������� FMSTR_CMD_READMEM_EX        0x04U
 [05] - ���������� ���� � ������ �� �������� ���������� ��� ����� � ���� ����������� �����
 [04] - ����� ������
 [f8][18][00][20] - �����
 [c3] - ����������� �����


������ ������� ������ ������ ��� �������� Scope
 [2b]
 [0a] - ������� FMSTR_CMD_SETUPSCOPE_EX     0x0aU
 [10] - ���������� ���� � ������ �� �������� ���������� ��� ����� � ���� ����������� �����
 [03] - ���������� ���������� � Scope
 [04] - ������ ������ ����������
 [84 1a 00  20] - ����� ������ ����������
 [04] - ������ ������ ����������
 [f8 18  00 20] - ����� ������ ����������
 [04] - ������ ������� ����������
 [98  1a 00 20] - ����� ������� ����������
 [17] - ����������� �����

������ ������� ������� ���������� �������� ��� �������� Scope
 [2b] - ������ ������
 [c5] - FMSTR_CMD_READSCOPE         0xc5U
 [3b] - ����������� �����

������ ������ �� ������
 [2b] - ������ ������
 [00] - ���������
 [00 00 00 00] - �������� ����������
 [00] - ����������� �����. ����������� ���:  ~(����� ���� ���� ����� 2b) + 1

������ ������� ������ ������ ��� �������� Recorder

 [2b] - ������ ������
 [0b] - ������� FMSTR_CMD_SETUPREC_EX       0x0bU
 [21] - ���������� ���� � ������ �� �������� ���������� ��� ����� � ���� ����������� �����
 [01] - ��� ������������ ������� ��� ������ ������
 [18 15] - ���������� �������
 [03 15] - ���������� ������� ������������ ����� ��������
 [01 00] - ������������ ������� �������
 [ac 2f  00 20] - ����� ���������� ��������
 [04] - ������ ���������� ��������
 [00] - ������ ��������� �������� (��������, �����������)
 [01 00 00 00] - �������� �������� ���������� ��������
 [03] - ���������� ������������ ����������
 [04] - ������ ������ ����������
 [98 1a  00 20] - ����� ������ ����������
 [04] - ������ ������ ����������
 [a0  1a 00 20] - ����� ������ ����������
 [04] - ������ ������� ����������
 [ec 2f 00 20] - ����� ������� ����������
 [97] - ����������� �����

������ ������� ������� ���������� �������� �������� Recorder
 [2b] - ������ ������
 [c3] - FMSTR_CMD_GETRECSTS         0xc3U    get the recorder status
 [3d] - ����������� �����

����� ��� ���������� ������
 [2b] - ������ ������
 [01] - FMSTR_STS_RECRUN            0x01U
 [ff] - ����������� �����

����� ��� ������� ������
 [2b] - ������ ������
 [02] - FMSTR_STS_RECDONE           0x02U
 [fe] - ����������� �����

������ ������� ������� ������ ��� �������� Recorder
 [2b] - ������ ������
 [c9] - FMSTR_CMD_GETRECBUFF_EX     0xc9U
 [37] - ����������� �����

������ ������ �� ������ ������ ��� �������� Recorder
 [2b] - ������ ������
 [00] - FMSTR_STS_OK                0x00U
 [b8 16 ff 1f] - ����� ������ � �������
 [96  02] - ������ ���������� ������� � ������ + 1 (pcm_wRecBuffStartIx)
 [7c] - ����������� �����

������ ������� �� ������ ������ �� ������� ��� �������� Recorder
 [2b] - ������ ������
 [04] - FMSTR_CMD_READMEM_EX        0x04U    read a block of memory
 [05] - ���������� ���� � ������ �� �������� ���������� ��� ����� � ���� ����������� �����
 [3c] - ���������� �������� ����
 [b8 16 ff 1f] - ��������� �����
 [cf] - ����������� �����


 */



uint8_t myhandler(uint8_t /*nAppcmd*/, uint8_t* /*pData*/, uint16_t /*nDataLen*/);


FMSTR_TSA_TABLE_LIST_BEGIN()
FMSTR_TSA_TABLE(tbl_vars)
#ifdef DOORCTL_APP
FMSTR_TSA_TABLE(tbl_doorctl_vars)
#endif
FMSTR_TSA_TABLE_LIST_END()

T_monitor_driver *frm_serial_drv;
  
/*-------------------------------------------------------------------------------------------------------------
  ������� ��������� ������ �������. �������������� �������� FMSTR_RegisterAppCmdCall
-------------------------------------------------------------------------------------------------------------*/
uint8_t myhandler(uint8_t code/*nAppcmd*/, uint8_t* pdata/*pData*/, uint16_t size/*nDataLen*/)
{
  return 0x10;  // ���������� ����� ����� ���������
}


/*-----------------------------------------------------------------------------------------------------
  ������� �������� �������������� ��������� FreeMaster
 
 \param src 
-----------------------------------------------------------------------------------------------------*/
void Frmstr_Set_recorder_smpls_src(uint32_t src)
{

  switch (src)
  {
  case FMSTR_SMPS_ADC_ISR:
    g_fmstr_rate_src = FMSTR_SMPS_ADC_ISR;
    g_fmstr_smpls_period = 1.0/(float)(MOT_PWM_FREQ);
    break;
  case FMSTR_SMPS_HALL_TMR_OVERFL_ISR:
    g_fmstr_rate_src = FMSTR_SMPS_HALL_TMR_OVERFL_ISR;
    g_fmstr_smpls_period = (float)(HALL_TMR_OVERFL_PERIOD_US)/1000000.0;
    break;
  case FMSTR_SMPS_SUPERVISOR_TASK:
    g_fmstr_rate_src = FMSTR_SMPS_SUPERVISOR_TASK;
    g_fmstr_smpls_period = 1.0/(float)(_time_get_ticks_per_sec());
    break;
  default:
    g_fmstr_rate_src = FMSTR_SMPS_ADC_ISR;
    g_fmstr_smpls_period = 1.0/(float)(MOT_PWM_FREQ);
    break;
  }
}


/*-------------------------------------------------------------------------------------------------------------
  ���� ������ FreeMaster
-------------------------------------------------------------------------------------------------------------*/
void Task_FreeMaster(uint32_t initial_data)
{

  uint16_t app_command;
  uint8_t  res;

  // �������� ��������� �� ������� ����������������� ����������  
  frm_serial_drv = (T_monitor_driver *)_task_get_parameter();

  Frmstr_Set_recorder_smpls_src(FMSTR_SMPS_ADC_ISR);

  if ( !FMSTR_Init() )
  {
    return;
  }

  // registering the App.Command handler
  // FMSTR_RegisterAppCmdCall(10, myhandler); �� ������������. ����� ������� ������� �������������� ��������� ����� Wait for result � �������, ����� ��������� ���������� �������

  while (1)
  {
    app_command = FMSTR_GetAppCmd();

    if ( app_command != FMSTR_APPCMDRESULT_NOCMD )
    {
      res = U3HB01_Freemaster_Command_Manager(app_command);
      FMSTR_AppCmdAck(res);
    }
    FMSTR_Poll();
  }
}


