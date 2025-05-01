#include "hal_data.h"
#include "globals/globals.h"
#include "dc/dc.h"
#include "irq/irq.h"
#include "uart/uart.h"
#include "bsp_warmstart/bsp.h"

void hal_entry(void)
{
    IRQ_Setting();
    DC_initial(); // 반시계방향 속도 0

    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_LOW); // PA08
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_09, BSP_IO_LEVEL_LOW); // PA09
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, BSP_IO_LEVEL_LOW); // PA10
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, BSP_IO_LEVEL_LOW); // PB00

    while(1) {

    }


#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}
