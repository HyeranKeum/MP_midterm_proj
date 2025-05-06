#include "hal_data.h"
#include "globals/globals.h"
#include "dc/dc.h"
#include "servo/servo.h"
#include "irq/irq.h"
#include "uart/uart.h"
#include "adc/adc.h"
#include "fnd/fnd.h"
#include "agt/agt.h"
#include "bsp_warmstart/bsp.h"


void hal_entry(void)
{
    initial_setting();

    system_on(); // P, auto로 초기화

    while(1) {

        ADC_Read_and_Convert();

        calc_TPS(); // TPS 업데이트

        set_gear(); // 기어 변경
        detect_error(); // 조도 센서 값따라 Error 업데이트

        set_servo();

        set_dc();

        fnd_print_state();

        AGT_ISR();
    }


#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}
