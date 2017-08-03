#ifndef USB_COMPOSITE_DEV_H
#define USB_COMPOSITE_DEV_H



#if HIGH_SPEED
  #define CONTROLLER_ID         USB_CONTROLLER_EHCI_0
  #define DATA_BUFF_SIZE        (HS_DIC_BULK_OUT_ENDP_PACKET_SIZE)
#else
  #define CONTROLLER_ID         USB_CONTROLLER_KHCI_0
  #define DATA_BUFF_SIZE        (FS_DIC_BULK_OUT_ENDP_PACKET_SIZE)
#endif



/* Implementation Specific Macros */
#define LINE_CODING_SIZE              (0x07)
#define COMM_FEATURE_DATA_SIZE        (0x02)

#define LINE_CODE_DTERATE_IFACE       (115200) /*e.g 9600 is 0x00002580 */
#define LINE_CODE_CHARFORMAT_IFACE    (0x00)   /* 1 stop bit */
#define LINE_CODE_PARITYTYPE_IFACE    (0x00)  /* No Parity */
#define LINE_CODE_DATABITS_IFACE      (0x08)  /* Data Bits Format */

#define STATUS_ABSTRACT_STATE_IFACE   (0x0000) /* Disable Multiplexing ENDP in this interface will continue to accept/offer data*/
#define COUNTRY_SETTING_IFACE         (0x0000) /* Country Code in the format as defined in [ISO3166]-- PLEASE CHECK THESE VALUES*/

#define VCOM_FLAG_RECEIVED             BIT( 0 )
#define VCOM_FLAG_TRANSMIT_EN           BIT( 1 )

#define  IN_BUF_QUANTITY   2           // ���������� �������� ������� 

// ����� ����� ���������� � N �������� �������
typedef struct
{
  uint8_t   *buff; // ����� � �������
  uint32_t  len;  // ����� ������
  uint32_t  pos;  // ������� ������� ���������� �����

} T_rx_pack_cbl;



typedef struct 
{
  uint32_t            port_indx;                    // ������ VCom �����. ������������ ������ � ���������� ����������
  cdc_handle_t        class_handle;
  uint16_t            device_speed;                 // �������� USB ����������

  bool                configured;                   // ���� ������������ ���������������� COM  �����
  bool                tx_enabled;                       // ���� ��������� ��� ������������ ������������ �����


  uint16_t            out_pack_sz;                  // 
  uint16_t            in_pack_sz;                   // 

  uint8_t            *rx_buf;                       //  ��������� �� ������� � �������� ������
  T_rx_pack_cbl       rx_pack_cbl[IN_BUF_QUANTITY]; //  ������ ����������� �������� ������-��������� �������� �������

  volatile uint8_t    rx_head;               //  ������ ������ ����������� ������� ������� ������
  volatile uint8_t    rx_tail;               //  ������ ������ ����������� ������� ������� ������
  volatile uint32_t   rx_full;               //  ���� ������������ ������� �������� ��������
  uint32_t            rx_errors;             //  ������� ������ �������� ������
  uint32_t            tx_errors; 
  LWEVENT_STRUCT      os_flags;              //  ���� ������������ ������ ������

} T_usb_cdc_vcom_struct;


/* Define the types for application */
typedef struct 
{
  uint16_t              speed;                          // Speed of USB device. USB_SPEED_FULL/USB_SPEED_LOW/USB_SPEED_HIGH.                 


  uint8_t               current_configuration;                                             /* Current configuration value. */
  //uint8_t               current_interface_alternate_setting[USB_CDC_VCOM_INTERFACE_COUNT]; /* Current alternate setting value for each interface. */
}
T_composite_dev;


typedef struct composite_device_struct
{
    composite_handle_t          composite_device;
    cdc_handle_t                cdc_vcom1;
    cdc_handle_t                cdc_vcom2;
    composite_config_struct_t   composite_device_config_callback;
    class_config_struct_t       composite_device_config_list[COMPOSITE_CFG_MAX];
} composite_device_struct_t;


uint32_t                 Composite_USB_device_init(void);



#endif // USB_COMPOSITE_DEV_H



