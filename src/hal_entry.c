#include "hal_data.h"
#include "globals/globals.h"
#include "dc/dc.h"
#include "servo/servo.h"
#include "irq/irq.h"
#include "uart/uart.h"
#include "adc/adc.h"
#include "fnd/fnd.h"
#include "bsp_warmstart/bsp.h"

char message[5];

int cnt = 0;
int Cnt = 65;

uint16_t p_RA;
uint16_t cds_sensor;
void hal_entry(void)
{
    initial_setting();

    system_on();

    while(1) {
        cnt += 1;
        if (cnt == 0xffff){
            cnt = 0;
            Cnt += 1;
            if (Cnt == 98) {
                Cnt = 65;
            }
        }
        ADC_Read_and_Convert();

        // 기어 변경(수동일 때만 수행)
        set_gear();

        calc_degree();
        Rotate_Servo();

        calc_dutyRate();
        Rotate_DC();
        
        // message[0] = (char) Cnt;
        // user_uart_write(message, strlen(message));

        R_FND_Print_Data(print_data);
    }


#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}
