#include "hal_data.h"
#include "globals/globals.h"
#include "dc/dc.h"
#include "irq/irq.h"
#include "uart/uart.h"
#include "adc/adc.h"
#include "bsp_warmstart/bsp.h"

char message[5];

int cnt = 0;
int Cnt = 0;

uint16_t p_RA;
uint16_t cds_sensor;
void hal_entry(void)
{
    IRQ_Setting();
    DC_initial(); // 반시계방향 속도 0

    R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
    R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);


    // ADC
    R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
    R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);

    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_LOW); // PA08
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_09, BSP_IO_LEVEL_LOW); // PA09
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, BSP_IO_LEVEL_LOW); // PA10
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, BSP_IO_LEVEL_LOW); // PB00

    while(1) {
        cnt += 1;
        if (cnt == 0xffff){
            cnt = 0;
            Cnt += 1;
        }
        ADC_Read_and_Convert();

        // message[0] = char_p;
        // user_uart_write(message, strlen(message));
    }


#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}
