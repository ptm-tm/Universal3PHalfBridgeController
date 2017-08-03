#ifndef U3HB01__APP_IDS
  #define U3HB01__APP_IDS


//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ ��������� BA100
//******************************************************************************************************************************************************
#define PLATFLR0_BTPSH_ID                0x0101
#define PLATFLR0_BTRLS_ID                0x0201
#define PLATFLR1_BTPSH_ID                0x0102
#define PLATFLR1_BTRLS_ID                0x0202
#define PLATFLR2_BTPSH_ID                0x0103
#define PLATFLR2_BTRLS_ID                0x0203
#define PLATFLR3_BTPSH_ID                0x0104
#define PLATFLR3_BTRLS_ID                0x0204
#define PLATFLR4_BTPSH_ID                0x0105
#define PLATFLR4_BTRLS_ID                0x0205
#define PLATFLR5_BTPSH_ID                0x0106
#define PLATFLR5_BTRLS_ID                0x0206
#define PLATFORM_BELL_BTPSH_ID           0x0110
#define PLATFORM_BELL_BTRLS_ID           0x0210
#define PLATFORM_STOP_BTPSH_ID           0x0111
#define PLATFORM_STOP_BTRLS_ID           0x0211

// �������������� ������� �������� ��� ���������
#define PLATFORM_PLAY_SOUND_ID           0x0500 // ������� �� ������������ �����
                                                // data[0] - ����� �����

#define PLATFORM_SET_LED_STATE_ID        0x0501 // ���������� ���������� ����������� �� ���������
                                                // data[0] - ��� ����������
                                                // data[1] - ����� ����������
                                                // data[2] - ���������
                                                // data[3] - ����

#define PLATFORM_EMERG_LIGHT_CTRL        0x0502 // ������� ���������� ��������� ����������
                                                // data[0] - ��������� ��������� (1 - �������, 0 - ���������)


#define PLATFORM_SEND_MSG_TO_SPORT       0x503  //
                                                // data[0] - hi byte of cmd num
                                                // data[1] - lo byte of cmd num

// �������������� �������� �������� �� ���������
#define PLATFORM_SIG_STATE_ID           0x0600 // ��������� � ��������� ��������� ������� Safety circuit
                                                // data[0].0 - Upper emergency limit switch
                                                // data[0].1

                                                // data[0].2 - Safety gear
                                                // data[0].3

                                                // data[0].4 - Safety bar 4
                                                // data[0].5

                                                // data[0].6 - Safety bar 3
                                                // data[0].7

                                                // data[1].0 - Safety bar 2
                                                // data[1].1

                                                // data[1].2 - Safety bar 1
                                                // data[1].3

                                                // data[1].4 - Emergency stop button
                                                // data[1].5

#define PLATF_UPGRADE_RX_ID              0x0100FFFF  // ������������� ������� �� ����� ��������� BA100  � ���������������� ����������
#define PLATF_UPGRADE_TX_ID              0x0101FFFF  // ������������� ������� �� ���������������� ���������� � ����� ��������� BA100

//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ FrontEnd (������������  ������ � �������� ��������� �� ��������� )������� SB200M
//******************************************************************************************************************************************************
#define SB200MFE_ESC_EVENT_ID            0x0010FFFF  // ������� ������ ������� �������� ��������� ���� �����������
                                                     // data[0] - ������� ����� ��������� ��������
                                                     // data[1] - ������� ����� ��������� ��������
                                                     #define FE_ESC1  8// BIT(8) - ESC1 log.state
                                                     #define FE_ESC2  7// BIT(7) - ESC2 log.state
                                                     #define FE_ESC3  6// BIT(6) - ESC3 log.state
                                                     #define FE_ESC4  5// BIT(5) - ESC4 log.state
                                                     #define FE_ESC5  4// BIT(4) - ESC5 log.state
                                                     #define FE_ESC6  3// BIT(3) - ESC6 log.state
                                                     #define FE_ESC7  2// BIT(2) - ESC7 log.state
                                                     #define FE_ESC8  1// BIT(1) - ESC8 log.state
                                                     #define FE_ESC9  0// BIT(0) - ESC9 log.state

#define SB200MFE_BTN_EVENT_ID            0x0011FFFF  // ������� ������ ������� ������
                                                     // data[0..3] - ������������ �������
                                                     #define  PRESS_PLATFORM_BUTTON       0x00010000 // +n  n - ����� �����
                                                     #define  RELEASE_PLATFORM_BUTTON     0x00020000 // +n
                                                     #define  LONG_PRESS_PLATFORM_BUTTON  0x00060000 // +n
                                                     #define  PRESS_BELL_BUTTON           0x00070000
                                                     #define  RELEASE_BELL_BUTTON         0x00080000
                                                     #define  PRESS_STOP_BUTTON           0x00090000
                                                     #define  RELEASE_STOP_BUTTON         0x000A0000
                                                     #define  PRESS_FLOOR_BUTTON          0x000B0000
                                                     #define  RELEASE_FLOOR_BUTTON        0x000C0000
                                                     #define  ORDER_TO_MOVE_BUTTON        0x000D0000 // ������ ������������ ��������, ������������ ��� ������������
                                                     #define  IBUTTON_CODE                0x000E0000 // ��������� � ������ ���� iButton �� �����������


#define SB200MFE_LEDS_GET_ID             0x0012FFFF  // ��������� ����� � �������� ��������� �������� �����������
                                                     // ����� �������� � ��� �� ��������������� ������
                                                     // data[0]..[1] - ������� ����� ��������� ���� unsigned short
                                                       #define FE_LED_STOP      0  //
                                                       #define FE_LED_OVERLOAD  1  //
                                                       #define FE_COLR_RED      2  //
                                                       #define FE_COLR_GREEN    3  //
                                                       #define FE_COLR_BLUE     4  //
                                                       #define FE_LED_BTN0      5  //
                                                       #define FE_LED_BTN1      6  //
                                                       #define FE_LED_BTN2      7  //
                                                       #define FE_LED_BTN3      8  //
                                                       #define FE_LED_BTN4      9  //
                                                       #define FE_LED_BTN5      10 //

#define SB200MFE_LEDS_SET_ID             0x0013FFFF  // ��������� ����� ��� ��������� ��������� �����������
                                                     // data[0]..[1] - ������� ����� ���� unsigned short
                                                     // ���� ��� 15 = 1, �� ������� ����� ������������ ����� ��������� ��������� ���� �������� �����������
                                                     // ����������� ����� � ������� SB200MFE_LEDS_GET_ID
                                                     // ���� ��� 15 = 0, �� � ���� 14 ���������� ��������� �������, � � ����� 3..0 ��� ����� � ������������ �
                                                     // �������� � ������� SB200MFE_LEDS_GET_ID



#define SB200MFE_VAL_GET_ID              0x0014FFFF  // ��������� ����� � �������� �������� ����������
                                                     // data[0] - ������������ ����������
                                                     //  0 -  ����������� CPU (float)
                                                     //  1 -  ESC1_v (float)
                                                     //  2 -  ESC2_v (float)
                                                     //  3 -  ESC3_v (float)
                                                     //  4 -  ESC4_v (float)
                                                     //  5 -  ESC5_v (float)
                                                     //  6 -  ESC6_v (float)
                                                     //  7 -  ESC7_v (float)
                                                     //  8 -  ESC8_v (float)
                                                     //  9 -  ESC9_v (float)
                                                     // ����� �������� ������ � ��� �� ��������������� ������

#define SB200MFE_VAL_SET_ID              0x0015FFFF  // ��������� ����� ���������� �������� ����������
                                                     // data[0] - ������������ ����������
                                                     //  0 -  ������� ������������ ���������
                                                     //  1 -  ��������� (data[1] = 1) � ���������� (data[1] = 0) ������������ ���������
                                                     #define FE_LIGHT_INTENS      0 // ������� ������������ ���������
                                                     #define FE_LIGHT_CTRL        1 // ��������� (data[1] = 1) � ���������� (data[1] = 0) ������������ ���������
                                                     #define FE_OVERLOAD_CTRL     2 // ��������� (data[1] = 1) � ���������� (data[1] = 0) ������ ����������


#define SB200MFE_REQ_BTN_EVENT_ID        0x0016FFFF  // ������ �� ��������� ������� �������� ������ �� ������

#define SB200MFE_PLAYER_CMD_ID           0x0017FFFF  // ������� ������������� �������������� ���������
                                                     // data[0] - ��� �������
                                                     #define FE_PLR_CMD_SETT      0 // ��������� ���������� �������������
                                                        // data[1] - ����� ���������. data[2..5] - �������� ���������
                                                        #define FEPLCMD_ARRIVAL_GONG          0 // ��������� �������� ���������� app_vars.en_arrival_gong
                                                        #define FEPLCMD_FLOORS_ANNOUNCER      1 // ��������� �������� ���������� app_vars.en_floors_announcer
                                                        #define FEPLCMD_EN_VOICE_ANNOUNCER    2 // ��������� �������� ���������� app_vars.en_voice_announcer
                                                        #define FEPLCMD_VOICE_ATTENUATION     3 // ��������� �������� ���������� app_vars.voice_attenuation
                                                        #define FEPLCMD_FLOOR_NUM_OFFSET      4 // ��������� �������� ���������� app_vars.floor_num_offset
                                                     #define FE_PLR_CMD_PLAY      1 // ������� �� ������������ ������������� ���������
                                                        // data[1] - ����� ���������, data[2..5] - �������� ���������
                                                        #define FEPLCMD_MSG_ERROR_            0 //
                                                        #define FEPLCMD_MSG_EMERGENCY_STOP    1 //
                                                        #define FEPLCMD_MSG_SENSOR_NUMBER     2 //
                                                        #define FEPLCMD_MSG_OVERLOAD          3 //
                                                        #define FEPLCMD_MSG_OPENED_LOCK       4 //
                                                        #define FEPLCMD_MSG_SERVICE_MODE      5 //
                                                        #define FEPLCMD_MSG_WORK_MODE         6 //
                                                        #define FEPLCMD_MSG_CALIBRATING_DONE  7 //
                                                        #define FEPLCMD_MSG_FIRE_ALARM        8 //
                                                        #define FEPLCMD_ARRIVAL_SND           9 //

#define SB200FE_UPGRADE_RX_ID            0x001CFFFF  // ������������� ������� �� ����� FrontEnd  � ���������������� ����������
#define SB200FE_UPGRADE_TX_ID            0x001DFFFF  // ������������� ������� �� ���������������� ���������� � ����� FrontEnd

#define SB200MFE_HEARTBEAT               0x001FFFFF  // ������������� ��������� �� ����� FrontEnf � �� �����������������


//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ BackEnd  ������� SB200M
//******************************************************************************************************************************************************
#define SB200BE_UPGRADE_RX_ID            0x001EFFFF  // ������������� ������� �� ����� BackEnd  � ���������������� ����������
#define SB200BE_UPGRADE_TX_ID            0x001FFFFF  // ������������� ������� �� ���������������� ���������� � ����� BackEnd


//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ BaseUnit
//******************************************************************************************************************************************************
#define SB200BU_ESC_EVENT_ID             0x0020FFFF  // ������� ������ ������� �������� ��������� ���� ������������
                                                     // data[0]..[1] - ������� ����� ��������� �������� ���� unsigned short
                                                     // ��������� ����������� ���������� ESC_state
                                                     // BIT(5) - ESC1
                                                     // BIT(4) - ESC2
                                                     // BIT(3) - ESC3
                                                     // BIT(2) - ESC4
                                                     // BIT(1) - ESC5
                                                     // BIT(0) - ESC6

#define SB200BU_BTN_EVENT_ID             0x0021FFFF  // ������� ������ ������� ������
                                                     // data[0] - ������� ����� �������
                                                     #define  PRESS_BT1_AUTO                 BIT(0)
                                                     #define  RELEASE_BT1_AUTO               BIT(1)
                                                     #define  PRESS_BT2_UP                   BIT(2)
                                                     #define  RELEASE_BT2_UP                 BIT(3)
                                                     #define  PRESS_BT3_MANUAL               BIT(4)
                                                     #define  RELEASE_BT3_MANUAL             BIT(5)
                                                     #define  PRESS_BT4_DOWN                 BIT(6)
                                                     #define  RELEASE_BT4_DOWN               BIT(7)
#define SB200BU_SET_LED_STATE            0x0022FFFF  // ������� ��������� ��������� ����������� ������
                                                     // data[0..1] - ������� ����� ��������� ��������� �����������
                                                     #define  LED_BT1_AUTO_STATE             BIT(0) // ��������� ���������: 0 - ��������, 1- �������
                                                     #define  LED_BT1_AUTO_MASK              BIT(1) // ����� ��������� ���������: 0 - ��������� ������������, 1- ��������� ���������� �������� ���������
                                                     #define  LED_BT2_UP_STATE               BIT(2)
                                                     #define  LED_BT2_UP_MASK                BIT(3)
                                                     #define  LED_BT3_MANUAL_STATE           BIT(4)
                                                     #define  LED_BT3_MANUAL_MASK            BIT(5)
                                                     #define  LED_BT4_DOWN_STATE             BIT(6)
                                                     #define  LED_BT4_DOWN_MASK              BIT(7)


#define SB200BU_VAL_GET_ID               0x0023FFFF  // ��������� ����� BaseUnit � �������� �������� ����������
                                                     // data[0] - ������������ ����������
                                                     #define  CPU_TEMP_VID 0  //   ����������� CPU (float)
                                                     #define  ESC1_VID     1  //   ESC1_v (float)
                                                     #define  ESC2_VID     2  //   ESC2_v (float)
                                                     #define  ESC3_VID     3  //   ESC3_v (float)
                                                     #define  ESC4_VID     4  //   ESC4_v (float)
                                                     #define  ESC5_VID     5  //   ESC5_v (float)
                                                     #define  ESC6_VID     6  //   ESC6_v (float)
                                                     #define  V5V_VID      7  //   V5V_v  (float)
                                                     #define  V10V_VID     8  //   V10V_v (float)
                                                     #define  V24V_VID     9  //   V24V_v (float)
                                                     #define  VACC_VID     10 //   VACC_v (float)
                                                     #define  IACC_VID     11 //   IACC_v (float)
                                                     #define  EXALR_VID    12 //   EXALR_v(float)
                                                     // ����� �������� ������ � ��� �� ��������������� ������

#define SB200BU_SET_OUTPUT_STATE         0x0024FFFF  // ��������� ����� BaseUnit � �������� �� ��������� �������� ��������� �������
                                                     // data[0..1] - ������� ����� ��������� ��������� �������� ��������
                                                     #define  OUT_LIGHTING_STATE             BIT(0) // ��������� ���������: 0 - ��������, 1- �������
                                                     #define  OUT_LIGHTING_MASK              BIT(1) // ����� ��������� ���������: 0 - ��������� ������������, 1- ��������� ���������� �������� ���������
                                                     #define  OUT_HEATING_STATE              BIT(2)
                                                     #define  OUT_HEATING_MASK               BIT(3)
                                                     #define  OUT_MISC1_STATE                BIT(4)
                                                     #define  OUT_MISC1_MASK                 BIT(5)
                                                     #define  OUT_MISC2_STATE                BIT(6)
                                                     #define  OUT_MISC2_MASK                 BIT(7)
                                                     #define  OUT_EMLW_DIR_STATE             BIT(8)
                                                     #define  OUT_EMLW_DIR_MASK              BIT(9)
                                                     #define  OUT_EMLW_MODE_STATE            BIT(10)
                                                     #define  OUT_EMLW_MODE_MASK             BIT(11)
                                                     #define  OUT_ACC_ACT_STATE              BIT(12) // ������������ ����� � ���� ����������� ������������
                                                     #define  OUT_ACC_ACT_MASK               BIT(13)
                                                     #define  OUT_ACC_ON_STATE               BIT(14)
                                                     #define  OUT_ACC_ON_MASK                BIT(15)

#define SB200BU_SET_DIAGN_STRIP_STATE    0x0025FFFF  // ��������� ����� BaseUnit � �������� �������� ��������������� ������
                                                     // data[0] - ��� ���������������� ���������
                                                     #define  DIAGNM_LANDING 0x80 // ������������� ��������� � ��������� ���������. � ������� ����� ����� ��������� - 0..5
                                                     #define  BACKEND_DMSG   0x40 // ��������������� ��������� �� BackEnd �����
                                                        // ������� �������������� ����� � ����� data[1] ��������� BACKEND_DMSG
                                                        #define BEDMSG_ESC               BIT(0)
                                                        #define BEDMSG_UP_EM_LIM_SW      BIT(1)
                                                        #define BEDMSG_LW_EM_LIM_SW      BIT(2)
                                                        #define BEDMSG_MOT_OVERHEAT      BIT(3)
                                                        #define BEDMSG_REFERENCE_SW      BIT(4)
                                                        #define BEDMSG_WEAR_SW           BIT(5)
                                                        #define BEDMSG_UP_LIM_SW         BIT(6)
                                                        #define BEDMSG_LOST_FRNTND_CAN   BIT(7) // ������ ����� BackEnd � FrontEnd
                                                        // ������� �������������� ����� � ����� data[2] ��������� BACKEND_DMSG
                                                        #define BEDMSG_LOST_INVERT_CAN   BIT(0) // ������ ����� BackEnd � Inverter
                                                        #define BEDMSG_SOLENOID1_ERR     BIT(1)
                                                        #define BEDMSG_SOLENOID2_ERR     BIT(2)
                                                        #define BEDMSG_SOLENOID1_LIMERR  BIT(3)
                                                        #define BEDMSG_SOLENOID2_LIMERR  BIT(4)
                                                        #define BEDMSG_SPEED_ERROR       BIT(5)

                                                     #define  FRONTEND_DMSG  0x20 // ��������������� ��������� �� FrontEnd �����


                                                     #define  GENERAL_DMSG   0x10 // ������������� ���������
                                                        #define GENMSG_CRITMOTTEMP     BIT(0)  // ����������� ����������� ������
                                                        #define GENMSG_PHASEFAULT      BIT(1)  // ������ �������� ���������
                                                        #define GENMSG_BACKUPSTATE     BIT(2)  // ����� ���������� �������
                                                        #define GENMSG_CALIBRATING     BIT(4)  // ����� ����������
                                                        #define GENMSG_OVERLOAD        BIT(6)  // ����� ����������
                                                        #define GENMSG_FIREALARM       BIT(7)  // �������� �����
                                                        // ������� �������������� ����� � ����� data[2] ��������� BACKEND_DMSG
                                                        #define GENMSG_BLOCKMODE       BIT(0)  // ����� ����������
                                                        #define GENMSG_SERVMODE        BIT(1)  // ��������� �����
                                                        #define GENMSG_NORMMODE        BIT(2)  // ������� �����

#define SB200BU_PWR_EVENT_ID             0x0026FFFF  // ������� ������ ������� ���������� ���������� ��������
                                                     // data[0] - ������� ����� �������
                                                     #define  PREPARE_TO_POWER_OFF           BIT(0) // ���������� ����� ���� ������������, ����� 1 ��� ������� ����� ���������
                                                     #define  POWER_FROM_ACCUM               BIT(1) // ������� �������� �� ������������
                                                     #define  POWER_FROM_MAIN                BIT(2) // ������� �������� �� ����

#define SB200BU_FIREAL_EVENT_ID          0x0027FFFF  // ������� ������ ������� ��������� ��������� ����� FireAlarm
                                                     // data[0] - BIT(0) - ��������� �����

#define SB200BU_RAINBOW_EVENT_ID         0x0028FFFF  // ������� ����� ���������� ������� Rainbow
                                                     // data[0] = 1 - ��������, data[0] = 0 - ���������

#define SB200BU_HEARTBEAT                0x002FFFFF  // ������������� ��������� �� ����� BaseUnit � �� �����������������




//******************************************************************************************************************************************************
// �������������� ��� ������ � ������� ���������
//******************************************************************************************************************************************************
#define FLOOR0_ONBUS_MSG                 0x0C00FFFF  //
#define FLOOR0_ERR_ACK_MSG               0x0C04FFFF  //
#define FLOOR0_DATA_MSG                  0x0C08FFFF  //
#define FLOOR0_INF_REQ                   0x1040FFFF  //
#define FLOOR0_INP_MSG                   0x1080FFFF  //
#define FLOOR0_UPGRADE_RX_ID             0x1081FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR0_UPGRADE_TX_ID             0x1082FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������

#define FLOOR1_ONBUS_MSG                 0x0C40FFFF  //
#define FLOOR1_ERR_ACK_MSG               0x0C44FFFF  //
#define FLOOR1_DATA_MSG                  0x0C48FFFF  //
#define FLOOR1_INF_REQ                   0x10C0FFFF  //
#define FLOOR1_INP_MSG                   0x1100FFFF  //
#define FLOOR1_UPGRADE_RX_ID             0x1101FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR1_UPGRADE_TX_ID             0x1102FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������

#define FLOOR2_ONBUS_MSG                 0x0C80FFFF  //
#define FLOOR2_ERR_ACK_MSG               0x0C84FFFF  //
#define FLOOR2_DATA_MSG                  0x0C88FFFF  //
#define FLOOR2_INF_REQ                   0x1140FFFF  //
#define FLOOR2_INP_MSG                   0x1180FFFF  //
#define FLOOR2_UPGRADE_RX_ID             0x1181FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR2_UPGRADE_TX_ID             0x1182FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������

#define FLOOR3_ONBUS_MSG                 0x0CC0FFFF  //
#define FLOOR3_ERR_ACK_MSG               0x0CC4FFFF  //
#define FLOOR3_DATA_MSG                  0x0CC8FFFF  //
#define FLOOR3_INF_REQ                   0x11A0FFFF  //
#define FLOOR3_INP_MSG                   0x1200FFFF  //
#define FLOOR3_UPGRADE_RX_ID             0x1201FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR3_UPGRADE_TX_ID             0x1202FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������

#define FLOOR4_ONBUS_MSG                 0x0D00FFFF  //
#define FLOOR4_ERR_ACK_MSG               0x0D04FFFF  //
#define FLOOR4_DATA_MSG                  0x0D08FFFF  //
#define FLOOR4_INF_REQ                   0x1240FFFF  //
#define FLOOR4_INP_MSG                   0x1280FFFF  //
#define FLOOR4_UPGRADE_RX_ID             0x1281FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR4_UPGRADE_TX_ID             0x1282FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������

#define FLOOR5_ONBUS_MSG                 0x0D40FFFF  //
#define FLOOR5_ERR_ACK_MSG               0x0D44FFFF  //
#define FLOOR5_DATA_MSG                  0x0D48FFFF  //
#define FLOOR5_INF_REQ                   0x12C0FFFF  //
#define FLOOR5_INP_MSG                   0x1300FFFF  //
#define FLOOR5_UPGRADE_RX_ID             0x1301FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR5_UPGRADE_TX_ID             0x1302FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������

#define FLOOR6_ONBUS_MSG                 0x1303FFFF  //
#define FLOOR6_ERR_ACK_MSG               0x1304FFFF  //
#define FLOOR6_DATA_MSG                  0x1305FFFF  //
#define FLOOR6_INF_REQ                   0x1306FFFF  //
#define FLOOR6_INP_MSG                   0x1307FFFF  //
#define FLOOR6_UPGRADE_RX_ID             0x1308FFFF  // ������������� ������� �� ����������� ������  � ���������������� ����������
#define FLOOR6_UPGRADE_TX_ID             0x1309FFFF  // ������������� ������� �� ���������������� ���������� � ����������� ������


//******************************************************************************************************************************************************
//  ��������� ��������������� SB200
//******************************************************************************************************************************************************
#define INVERT_ONBUS_MSG                 0x1BF0FFFF  // ����������� ������� �� ����� ���������
#define INVERT_REQ                       0x1BF1FFFF  // ������� � ����� � �������� ������ ��� ��������
#define INVERT_ANS                       0x1BF2FFFF  // ������� �� ����� � ����� �� ������

// ��������������� INVERT_REQ ���������� ��������� ������� (���������� � ����� 0 ����� ������)
#define START_MOVING                     0x01 // ������ ��������
                                              // � �����  1 - ����������� (���� - 1, ����� - 0)
                                              // � ������ 2 -  ������� ������� �������� (��)
                                              // � ������ 3 -  ����� ��������� (� ������� ����� �������)

#define STOP_MOVING                      0x02 // ��������� ��������
                                              // � �����  1 - ����� ���������� (� ������� ����� �������)
#define EMERGENCY_STOP_MOVING            0x03 // ��������� ���������


#define INVERT_HEARTBEAT                 0x1BF3FFFF  // ������������� ��������� �� ����� Inverter � �� �����������������

#define INVERT_UPGRADE_RX_ID             0x1BF6FFFF  // ������������� ������� �� ���������� ���������������� � ���������������� ����������
#define INVERT_UPGRADE_TX_ID             0x1BF7FFFF  // ������������� ������� �� ���������������� ���������� � ���������� ����������������


//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ ���������
// ����� ����� ������������ � ���� 20...23 ��������������
//******************************************************************************************************************************************************

#define LIGHTx_ONBUS_MSG                 0x1C00FFFF  // ����������� ������� �� ����� ���������
#define LIGHTx_REQ                       0x1C01FFFF  // ������� � ����� ���������
#define LIGHTx_ANS                       0x1C02FFFF  // ������� �� ����� ���������
#define LIGHTx_UPGRADE_RX_ID             0x1C03FFFF  // ������������� ������� �� ����� ��������� � ���������������� ����������
#define LIGHTx_UPGRADE_TX_ID             0x1C04FFFF  // ������������� ������� �� ��������������� ���������� � ����� ���������

// ������ ������ ���������� ����� ��������� � ����� 0 ����� ������
#define LIGHT_SET_STATIC_RGB   0x01 // ���������� ���� � ������ 1,2,3 ���������� �������� R, G, B ��������������
#define LIGHT_SET_RUN_RGB      0x02 // � ������ 1,2,3 ���������� �������� R, G, B ���� � ������ 4,5,6 - ���� ����� , � ����� 6 � ���� 0 ���������� �����������
#define LIGHT_SET_RANDOM       0x03 // ���������� ������������ ����� ��������� �������
#define LIGHT_SET_OFF          0x04 // ��������� ����������


//******************************************************************************************************************************************************
// �������������� ��� ������ � ��������� 1Wire-CAN
// ����� ����� ������������ � ���� 20...23 ��������������
//******************************************************************************************************************************************************
#define D1WCANx_ONBUS_MSG                0x1D00FFFF  // ����������� ������� �� ����� ���������
#define D1WCANx_NEW_ID                   0x1D01FFFF  // ����������� ������� �� �������� � ����� 1Wire ����������
#define D1WCANx_REQ                      0x1D02FFFF  // ������� � �������� � �������� ������ ��� ��������
#define D1WCANx_ANS                      0x1D03FFFF  // ������� �� �������� � ����� �� ������
#define D1WCANx_UPGRADE_RX_ID            0x1D04FFFF  // ������������� ������� �� �������� 1Wire-CAN � ���������������� ����������
#define D1WCANx_UPGRADE_TX_ID            0x1D05FFFF  // ������������� ������� �� ��������������� ���������� � �������� 1Wire-CAN

// ��������������� D1WCANx_REQ ���������� ��������� ������� (���������� � ����� 0 ����� ������)
#define D1WCAN_SET_SOUND_PTTRN           0x01
#define D1WCAN_SET_LED_PTTRN             0x02
#define D1WCAN_GET_TEMPERATURE           0x03



//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ LED �������
// ����� ����� ������������ � ���� 20...23 ��������������
//******************************************************************************************************************************************************
#define PDISPLx_ONBUS_MSG                0x1E00FFFF  // ����������� ������� �� ����� LED �������
#define PDISPLx_REQ                      0x1E02FFFF  // ������� � ����� � �������� ������ ��� ��������
#define PDISPLx_ANS                      0x1E03FFFF  // ������� �� ����� � ����� �� ������
#define PDISPLx_UPGRADE_RX_ID            0x1E04FFFF  // ������� �� ����� �� ����� ����������������
#define PDISPLx_UPGRADE_TX_ID            0x1E05FFFF  // ������� � ����� �� ����� ����������������
#define PDISPLx_SET_RED_SYMB             0x1E06FFFF  // ������� � ����� 8-� ���� �������� �������
#define PDISPLx_SET_GREEN_SYMB           0x1E07FFFF  // ������� � ����� 8-� ���� �������� �������

// ��������������� PDISPLx_REQ ���������� ��������� ������� (���������� � ����� 0 ����� ������)
#define PDISPLx_SET_SYMBOL                0x01 // ��������� ������������ ������� � ����� � ����� 1 � ������ � ����� 2
#define PDISPLx_SET_SYMBOL_PTRN1          0x02 // ��������� 1-� �����  �������� ������� � ����� � ����� 1 , ����� �������� � ������ 4..7
#define PDISPLx_SET_SYMBOL_PTRN2          0x03 // ��������� 2-� �����  �������� ������� � ����� � ����� 1 , ����� �������� � ������ 4..7
#define PDISPLx_DIN_SYMBOL_SET1           0x04 // ���� 1 ��������� ������������� �������.
                                               // � �����  1 - ����� �������
                                               // � ������ 2..3 -  ������ ����� �����
                                               // � ������ 4..5 -  ���������� �����
#define PDISPLx_DIN_SYMBOL_SET2           0x05 // ���� 2 ��������� ������������� �������.
                                               // � �����  2..3 - ���������� �� x
                                               // � ������ 4..5 - ���������� �� y
#define PDISPLx_DIN_SYMBOL_SET3           0x06 // ���� 2 ��������� ������������� �������.
                                               // � �����  2..3 - ��������� �������� x
                                               // � ������ 4..5 - ��������� �������� y
#define PDISPLx_DIN_SYMBOL_SET4           0x07 // ���� 2 ��������� ������������� �������.
                                               // � �����  1 - ���� ������� (0 - �������, 1 - �������)


//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ ���������� �������� BA100
//******************************************************************************************************************************************************
#define PWRMOD_TO_SYS                    0x1E71FFFF  // ������� ������ �� ����� ���������� �������� � ������������ ����� ����������
                                                     // data[0] - ��� �������
                                                     // data[1]...data[7] - ������
/*
  �������� ������ � ������

---1.--- �� ����� ���������� �������� � ������������ ����� ����������

  data[0] = 0x01 - ������� ������
  data[1] = 0x01 - �������, 0x02 - ����������
  data[2] = 0x01 (normal), 0x02 (manual), 0x03 (UP), 0x04 (DOWN)

  � ����� ������ ���� �������� ������� ������������� �� ������������ ����� � ���� �� �������

---2.--- �� ������������ ����� � ����� ���������� ��������

  data[0] = 0x02 - ������� ������� ����� ���������� ��������

  � ����� ������ ���� �������
  data[0] = 0x02 - ������� ������� ����� ���������� ��������
  data[1] = 0xXX - ������ �����

---3.--- �� ������������ ����� � ����� ���������� ��������

  data[0] = 0x03 - ������ �� ����������� ����� �� ��������� �������� ���������

  � ����� ������ ���� �������� �� �� �������

---4.--- �� ����� ���������� �������� � ������������ ����� ����������

  data[0] = 0x04 - ������ �� ����������� ����� �� ���������� �������� ���������

  � ����� ������ ���� �������� �� �� �������

*/

// ���������� ����� 0 ������� � �������������� PWRMOD_TO_SYS
#define PWRMOD_KEY_EVNT_CMD 0x01
#define PWRMOD_BRD_REQ      0x02
#define PWRMOD_TRACTION_ON  0x03
#define PWRMOD_TRACTION_OFF 0x04

// ���������� ����� 1 ������� PWRMOD_KEY_EVNT_CMD
#define   PWRMOD_KEY_PRESS     0x01
#define   PWRMOD_KEY_RELEASE   0x02

// ���������� ����� 2 ������� PWRMOD_KEY_EVNT_CMD
#define   PWRMOD_KEY_NORMAL     0x01
#define   PWRMOD_KEY_MANUAL     0x02
#define   PWRMOD_KEY_UP         0x03
#define   PWRMOD_KEY_DOWN       0x04
#define   PWRMOD_KEY_FIRE_ALR   0x05





#define PWRMOD_FROM_SYS                  0x1E72FFFF  //
#define PWRMOD_ONBUS_MSG                 0x1E73FFFF  //

#define PWRMOD_DATA_PACKET_TO_SYS        0x1E74FFFF  // ������� ����� ������ ������������ ����� �� ����� ���������� �������� � ������������ ����� ����������

#define   COMCH_SET_PARAMS        0x10  // ������� ��������� ���������� ������ ����������
#define   COMCH_GET_PARAMS        0x01  // ������� ������� ���������� ������ ����������
#define   COMCH_PARAMS_ANS        0x81  // ����� ������ � ����������� ����� � ����������� ������ ����������

#define   COMCH_GET_SYSVALS       0x03
#define   COMCH_SYSVALS_ANS       0x83  // ����� ������ � ����������� ����� �� ���������� ��������� �������

#define   COMCH_SET_ALARM         0x8E  // ����� ������� � ����������� ����� � ��������� ��������� �������
#define   COMCH_PREPARE_OFF       0x8F  // ����� ���������� � ���������� � ����������� �����
#define   COMCH_RESET_ALARM       0x0F  // ����� ��������� ������� �� ����������� �����
#define   COMCH_SYS_OFF           0xFF  // ��������� �� ����������� ����� � �������� ������� � ����������� ��������� ���� �� ������������� ���������� ���������
#define   COMCH_SYS_RESET         0xFE  // ��������� �� ����������� ����� � ������ �������


#define PWRMOD_DATA_PACKET_FROM_SYS      0x1E75FFFF  // ������� ����� ������ ������������ ����� �� ������������ ����� ���������� � ����� ���������� �������� �
#define PWRMOD_UPGRADE_RX_ID             0x1E76FFFF  // ������������� ������� �� ����� ���������� �������� BA100 � ���������������� ����������
#define PWRMOD_UPGRADE_TX_ID             0x1E77FFFF  // ������������� ������� �� ��������������� ���������� � ����� ���������� �������� BA100

//******************************************************************************************************************************************************
// �������������� ��� ������ � ������ ���������� ��������������� ������� 
// ����� ����� ������������ � ���� 20...23 ��������������
//******************************************************************************************************************************************************
#define DMC01_ONBUS_MSG            0x1A00FFFF  // ����������� ������� �� ����� ���������� ��������������� ������� 
#define DMC01_REQ                  0x1A01FFFF  // ������ ������ 
                                               // data[0] - ������������ �������
#define DMC01_REQ_STATUS                          0x01 // ������� ������� ������� 
#define DMC01_REQ_ZERO                            0x02 // ������� ��������� ������� 
#define DMC01_REQ_OPEN                            0x03 // ������� ������� �����
#define DMC01_REQ_CLOSE                           0x04 // ������� ������� �����
#define DMC01_REQ_BRAKE                           0x05 // ������� ����������� �����
#define DMC01_REQ_FORCEBRAKE                      0x06 // ������� ����������� ����������� �����

#define DMC01_ANS                  0x1A02FFFF  // ����� � ������� 


//******************************************************************************************************************************************************
// �������������� ��� ����� ������ ��������������������
//******************************************************************************************************************************************************
#define   ALL_ENTER_TO_WRK_MOD              0x0001FFFF // ������� ���� ������� � ������� �����
#define   ALL_PROLONG_BOOT_MODE             0x0002FFFF // ������� ���� �������� ����������� �����
#define   ALL_ENTER_TO_BOOT_MOD             0x0003FFFF // ������� ���� ������� � ����������� �����

#define   BOOTL_GET_CRC           0x10  // ������� ������� ����������� �����
#define   BOOTL_ACK_CRC           0x11  // ����� �� ������ ����������� �����
#define   BOOTL_ACK_ERASE         0x12  // ����� � ���������� ���������

#define   BOOTL_SET_BOOT_REC      0x20  // ������� � ���������� ����������� ������
#define   BOOTL_ERASE_FLASH       0x21  // ������� �������� FLASH
#define   BOOTL_DO_PRG            0x30  // ������� ��������� ���������������� �����
#define   BOOTL_ACK_PRG           0x31  //


#endif
