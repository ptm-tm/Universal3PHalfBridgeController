#ifndef U3HB01_ROTATIONCONTROL_H
#define U3HB01_ROTATIONCONTROL_H

#define EVT_ROTATION_ON                BIT(0)
#define EVT_ROTATION_OFF               BIT(1)
#define EVT_ROTATION_FORCEBRAKE        BIT(2)
#define EVT_ROTATION_FREERUN           BIT(3)
#define EVT_ROTATION_ENC_DAT_READY     BIT(4)

#define ROT_CMD_FORCE_BREAK        1
#define ROT_CMD_BREAK              2
#define ROT_CMD_FREERUN            3
#define ROT_CMD_START              4

// ����������� ��������� ��������� ���������� ������ �������� �����
typedef struct
{
  uint32_t cmd_flags;
  uint32_t last_cmd_flags;
   
  uint32_t step_cnt;                          // ������� ������� � ������� ����
  uint32_t start_pos;                         // ��������� �������
  uint32_t end_pos;                           // �������� �������




} T_rotation;

void      U3HB01_Rot_post_evt(_mqx_uint evts);
uint32_t  U3HB01_Rotation_control(void);



#endif // U3HB01_ROTATIONCONTROL_H



