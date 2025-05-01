#include "hal_data.h"
#include "../globals/globals.h"
#include "../dc/dc.h"
#include "../servo/servo.h"
#include "irq.h"

void IRQ_Setting() {
    R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq12_ctrl, &g_external_irq12_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq12_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq13_ctrl, &g_external_irq13_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq13_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq14_ctrl, &g_external_irq14_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq14_ctrl);
}


void R_IRQ_Interrupt(external_irq_callback_args_t *p_args)
{
    uint32_t switch_channel;
    switch_channel = p_args -> channel;

    switch (switch_channel) {
        case 11:{
            Toggle += 1;
            L293_CH0_Direction_Level = BSP_IO_LEVEL_HIGH; // 시계방향
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
            break;
        }
        case 12: {
            L293_CH0_Direction_Level = BSP_IO_LEVEL_LOW; // 반시계방향
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
            break;
        }
        case 13: {
            if(degree != 180)
                degree += 10;

            Rotate_Servo();
            break;
        }
        case 14: {
            if(degree != 0)
                degree -= 10;

            Rotate_Servo();
            break;
        }
    }
}
