#ifndef __PARAMS
  #define __PARAMS

#define  APP_PROFILE        U3HB01
#define  MAIN_PARAMS_ROOT   U3HB01_main
#define  PARAMS_ROOT        U3HB01_0

#define  DWVAR_SIZE        13
#define  PARMNU_ITEM_NUM   4



  #define VAL_LOCAL_EDITED 0x01  //
  #define VAL_READONLY     0x02  // ����� ������ ������
  #define VAL_PROTECT      0x04  // �������� �������
  #define VAL_UNVISIBLE    0x08  // �� ��������� �� �������
  #define VAL_NOINIT       0x10  // �� ����������������


enum vartypes
{
    tint8u  = 1,
    tint16u  = 2,
    tint32u  = 3,
    tfloat  = 4,
    tarrofdouble  = 5,
    tstring  = 6,
    tarrofbyte  = 7,
    tint32s  = 8,
};


enum enm_parmnlev
{
    U3HB01_Spec,
    U3HB01_0,
    U3HB01_main,
    U3HB01_General,
    U3HB01_Rotation,
};


typedef struct 
{
  enum enm_parmnlev prevlev;
  enum enm_parmnlev currlev;
  const char* name;
  const char* shrtname;
  const char  visible;
}
T_parmenu;


typedef struct
{
  const uint8_t*     name;         // ��������� ��������
  const uint8_t*     abbreviation; // �������� ������������
  void*              val;          // ��������� �� �������� ���������� � RAM
  enum  vartypes     vartype;      // ������������� ���� ����������
  float              defval;       // �������� �� ���������
  float              minval;       // ����������� ��������� ��������
  float              maxval;       // ������������ ��������� ��������  
  uint8_t            attr;         // ��������� ����������
  unsigned int       parmnlev;     // ��������� � ������� ����������� ��������
  const  void*       pdefval;      // ��������� �� ������ ��� �������������
  const  char*       format;       // ������ �������������� ��� ������ �� �������
  void               (*func)(void);// ��������� �� ������� ����������� ����� ��������������
  uint16_t           varlen;       // ������ ����������
} T_work_params;


typedef struct
{
  uint8_t        dev_task;                      // Device task ( 1-Solenoid, 2-Rotation) | def.val.= 1
  uint8_t        en_log_file;                   // Enable log to file | def.val.= 1
  uint8_t        en_speed_fltr;                 // Enable speed filter | def.val.= 1
  uint8_t        en_verbose_log;                // Enable verbose log | def.val.= 0
  uint8_t        led_strip_en;                  // Enable LED strip control | def.val.= 0
  float          max_curr;                      // Max current (A, rms) | def.val.= 10
  float          max_long_curr;                 // Max long current (A, rms) | def.val.= 3
  uint8_t        name[64];                      // Product  name | def.val.= MDC 1.0
  uint8_t        rot_dir;                       // Rotation direction (0-CW, 1-CCW) | def.val.= 0
  uint8_t        rot_fbreak_pwm_lev;            // Force break PWM level(0..100%) | def.val.= 5
  uint8_t        rot_pwm_lev;                   // PWM level (0..100%) | def.val.= 25
  uint32_t       rot_steps;                     // Rotation step (pulse count) | def.val.= 0
  uint8_t        ver[64];                       // Firmware version | def.val.= ?
} WVAR_TYPE;


#endif
