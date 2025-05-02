#include "hal_data.h"
#include "../globals/globals.h"
#include "../dc/dc.h"
#include "../servo/servo.h"
#include "../fnd/fnd.h"
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
            f1 += 1;
            print_data[0] = fnd1[(f1)%4];
            break;
        }
        case 12: {
            f2 += 1;
            print_data[1] = fnd2[(f2)%2];
            break;
        }
        case 13: {
            f3 += 1;
            print_data[2] = fnd3[(f3)%5];
            break;
        }
        case 14: {
            f4 += 1;
            print_data[3] = fnd4[(f4)%2];
            break;
        }
    }
}
