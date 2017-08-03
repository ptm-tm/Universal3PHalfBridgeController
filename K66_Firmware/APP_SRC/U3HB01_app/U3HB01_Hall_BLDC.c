// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2017-01-04
// 21:35:50
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"
#include   "FreeMaster.h"




// ������ � ������� �������� ��������� �������� �����, � �������� ���������� ��������� �������
const static T_commutation_tbl hall_commutation_tbl[6] =
{
  { 0x0030,    0x0001,   1  , -1  ,  0 }, //  C (P3) switched off,  A inverted (high lev.) , B normal   (low. lev.), � normal   (low. lev.).  State 0
  { 0x000C,    0x0001,   1  ,  0  , -1 }, //  B (�2) switched off,  A inverted (high lev.) , B normal   (low. lev.), � normal   (low. lev.).  State 1
  { 0x0003,    0x0002,   0  ,  1  , -1 }, //  A (�1) switched off,  A normal   (low. lev.) , B inverted (high lev.), � normal   (low. lev.).  State 2
  { 0x0030,    0x0002,  -1  ,  1  ,  0 }, //  C (�3) switched off,  A normal   (low. lev.) , B inverted (high lev.), � normal   (low. lev.).  State 3
  { 0x000C,    0x0004,  -1  ,  0  ,  1 }, //  B (�2) switched off,  A normal   (low. lev.) , B normal   (low. lev.), � inverted (high lev.).  State 4
  { 0x0003,    0x0004,   0  , -1  ,  1 }, //  A (�1) switched off,  A normal   (low. lev.) , B normal   (low. lev.), � inverted (high lev.).  State 5
};


// ���������� ��� ���������� ���������� ���������

// ������� ��������� ��������� ��� �������� �� ������� � ������ �������. ����� �������� ������� ���������, �������� - ���������
// �� �������� ��������� ���������� ������������ ������� � ������� hall_commutation_tbl
const  uint32_t                sync_ctrl_trans_tbl[2][6]  =
{
  {1,2,3,4,5,0},{4,5,0,1,2,3}
};

/*-----------------------------------------------------------------------------------------------------
 �������� � ���������� ���������� ������ �������� ��������  
 
 \param hst 
-----------------------------------------------------------------------------------------------------*/
static void _Set_motor_debug_vars(uint32_t hst)
{
  bldcs_cbl.a_out_level = hall_commutation_tbl[hst].mot_a_out * mot_PWM_lev;
  bldcs_cbl.b_out_level = hall_commutation_tbl[hst].mot_b_out * mot_PWM_lev;
  bldcs_cbl.c_out_level = hall_commutation_tbl[hst].mot_c_out * mot_PWM_lev;
}


/*-----------------------------------------------------------------------------------------------------
   ����� �������� ��������� � ���������� ������
 
 
-----------------------------------------------------------------------------------------------------*/
uint32_t BLDC_start_rotation(uint32_t direction, float pwr)
{
  uint32_t mod;
  uint32_t hst;

  if (g_bldc_active == 0)
  {

    // ������ ��������� �������� �����
    hst = U3HB01_get_hall_state();
    if ((hst < 1) || (hst > 6))
    {
      g_app_errors |= APP_ERR_HALL_STATE_FAULT;
      return MQX_ERROR;
    }
    g_app_errors &= ~APP_ERR_HALL_STATE_FAULT;

    hst = Get_Hall_state_from_mask(hst); // �������� ����� ��������� �� ����� ���������

    if (direction == CCW_MOTOR_ROTATION)
    {
      bldcs_cbl.rot_dir = CCW_DIR ^ bldcs_cbl.dir_inv;
    }
    else if (direction == CW_MOTOR_ROTATION)
    {
      bldcs_cbl.rot_dir = CW_DIR ^ bldcs_cbl.dir_inv;
    }
    else return MQX_ERROR;

    // ���������� ������������ ������� �������
    hst = sync_ctrl_trans_tbl[bldcs_cbl.rot_dir][hst];
    bldcs_cbl.commutation_step = hst;
    // �������� ������� �������
    FTM3_SWOCTRL = 0;        // �������� ���������� ���������� �������
    FTM3_OUTMASK = hall_commutation_tbl[hst].outmask;
    FTM3_INVCTRL = hall_commutation_tbl[hst].outinv;

    mod = Get_modulation_from_percent(pwr);
    mot_PWM_lev = (int16_t)pwr;
    FTM3_set_CnV(mod);

    _Set_motor_debug_vars(hst);
    DRV8305_Gates_enable();

    g_bldc_active = 1;
    g_bldc_forcebrake = 0;
    return MQX_OK;
  }
  else
  {
    if (direction == CCW_MOTOR_ROTATION)
    {
      bldcs_cbl.rot_dir = CCW_DIR ^ bldcs_cbl.dir_inv;
    }
    else if (direction == CW_MOTOR_ROTATION)
    {
      bldcs_cbl.rot_dir = CW_DIR ^ bldcs_cbl.dir_inv;
    }
    else return MQX_ERROR;

    mod = Get_modulation_from_percent(pwr);
    mot_PWM_lev = (int16_t)pwr;
    FTM3_set_CnV(mod);

    return MQX_OK;
  }
}

/*-----------------------------------------------------------------------------------------------------
  ������������� ���������� ������� ������������ ���� �� �������
 
 \param pwr 
-----------------------------------------------------------------------------------------------------*/
void BLDC_force_break(float pwr)
{
  uint32_t   hst;

  mot_PWM_lev = (int8_t)pwr;
  FTM3_set_CnV(Get_modulation_from_percent(pwr));

  hst = Get_hall_state();
  // ���������� ����������� ������������ ���������� �������
  hst = sync_ctrl_trans_tbl[bldcs_cbl.rot_dir][hst];
  bldcs_cbl.commutation_step = hst;
  // ������������� ������������ ���������� �������
  FTM3_SWOCTRL = 0;        // �������� ���������� ���������� �������
  FTM3_OUTMASK = hall_commutation_tbl[hst].outmask;
  FTM3_INVCTRL = hall_commutation_tbl[hst].outinv;
  DRV8305_Gates_enable();
  g_bldc_active = 1;
  g_bldc_forcebrake = 1;
  _Set_motor_debug_vars(hst);  // ���������� ���������� ����������
}


/*-----------------------------------------------------------------------------------------------------
  ���� ��������� ������������� � ������� ����������� PWM ������ ������ ���� ��������� ����� ����
  ��� �� ��� �������� ����� �������� ������������� ��������
 
  ������� ��������� ��� � ��������� ������� ���������� ��������� ����� ���� �������� � �������� ������� 
 
 \param void 
-----------------------------------------------------------------------------------------------------*/
void BLDC_set_PWM_sync_signal(void)
{
  FTM3_SYNC |= BIT(7);
}

/*-----------------------------------------------------------------------------------------------------
  ������ ������������ ��������� BLDC ������ �� ������� � �������� �����
  ���������� �� ��������� ���������� Hall_sensor_kernel_isr �� ������� ��������� ��������� �������� ����� 
  ���������� ������ ����!!!
 
 \param hst   - ����� ��������� �������� �����
-----------------------------------------------------------------------------------------------------*/
void BLDC_commutation_by_hall_sens(uint32_t hst)
{
  if ((g_bldc_active) && (g_bldc_forcebrake == 0))
  {

    // ���������� ����������� ������������ ���������� �������
    hst = sync_ctrl_trans_tbl[bldcs_cbl.rot_dir][hst];
    bldcs_cbl.commutation_step = hst;
    // ������������� ������������ ���������� �������
    FTM3_OUTMASK = hall_commutation_tbl[hst].outmask;
    FTM3_INVCTRL = hall_commutation_tbl[hst].outinv;
    _Set_motor_debug_vars(hst);  // ���������� ���������� ����������
  }
}

/*-----------------------------------------------------------------------------------------------------
  ������������ ����������
  ���������� �� ��������� ����� ���������� � �������� PID_PERIOD_US
 
 
 \param void 
 
 \return uint32_t  �� 0 ���� ���������� ����������� 
-----------------------------------------------------------------------------------------------------*/
uint32_t BLDC_overload_observer(void)
{
  T_currents *pcurr;
  uint32_t    res = 0;
  // ���� ����������  ����������� ����� � �������� ���������� �� ����
  pcurr = DRV8305_get_shunt_currents();

  // ������� ������� �������� ����� � ������ ���� �� ������ ����� ���������� 
  ovrc_cbl.aver_curr_a = (float)pcurr->ia_acc * SHUNT_CURRENT_TO_FLOAT / pcurr->curr_acc_cnt;
  ovrc_cbl.aver_curr_b = (float)pcurr->ib_acc * SHUNT_CURRENT_TO_FLOAT / pcurr->curr_acc_cnt;
  ovrc_cbl.aver_curr_c = (float)pcurr->ic_acc * SHUNT_CURRENT_TO_FLOAT / pcurr->curr_acc_cnt;

  ovrc_cbl.long_aver_curr_a += ovrc_cbl.aver_curr_a;
  ovrc_cbl.long_aver_curr_b += ovrc_cbl.aver_curr_b;
  ovrc_cbl.long_aver_curr_c += ovrc_cbl.aver_curr_c;
  ovrc_cbl.long_curr_cnt++;

  if (ovrc_cbl.long_curr_cnt > LONG_CURRENT_SMPLS_NUM)
  {
    float bound =  ovrc_cbl.max_long_current * (float)LONG_CURRENT_SMPLS_NUM;
    if ((ovrc_cbl.long_aver_curr_a > bound) || (ovrc_cbl.long_aver_curr_b > bound) || (ovrc_cbl.long_aver_curr_c > bound))
    {
      ovrc_cbl.overload_flags = OVERLOAD_HIGH_LONG_CURRENT;
      res = 1;
    }

    ovrc_cbl.long_aver_curr_a = 0;
    ovrc_cbl.long_aver_curr_b = 0;
    ovrc_cbl.long_aver_curr_c = 0;
    ovrc_cbl.long_curr_cnt = 0;
  }

  DRV8305_clear_currents_acc(); // ������� ���������� �����

  if ((ovrc_cbl.aver_curr_a > ovrc_cbl.max_current) || (ovrc_cbl.aver_curr_b > ovrc_cbl.max_current) || (ovrc_cbl.aver_curr_c > ovrc_cbl.max_current))
  {
    ovrc_cbl.overload_flags = OVERLOAD_HIGH_SHORT_CURRENT;
    res = 1;
  }
  return res;
}


