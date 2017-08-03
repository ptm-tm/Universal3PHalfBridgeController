#ifndef U3HB01_BLDC_H
#define U3HB01_BLDC_H

#define   CW_DIR              0 
#define   CCW_DIR             1 
                              
#define   ASYNC_MOT_CONTROL   0
#define   SYNC_MOT_CONTROL    1


#define  NO_OVERLOAD                 0
#define  OVERLOAD_HIGH_LONG_CURRENT  1
#define  OVERLOAD_HIGH_SHORT_CURRENT 2

typedef struct
{
  uint32_t outmask;
  uint32_t outinv;

  // ���������� ��� ����������� ������ ���������� ��������� �������
  uint8_t  mot_a_out;
  uint8_t  mot_b_out;
  uint8_t  mot_c_out;


}  T_commutation_tbl;

typedef struct
{
  const char    *vname; // ��� ����������
  uint16_t      *pval;  // ��������� �� ���������� ����������  �������� �������� 
  uint16_t      defv;   // ����������������� ���������
} T_BLDC_pars_map;


void              BLDC_Free_Run(void);
void              BLDC_break(void);

#endif // MDC01_BLDC_H



