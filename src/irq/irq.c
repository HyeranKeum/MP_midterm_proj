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
            current_lever += 1;
            if (current_lever == 4){
                current_lever = 0;
            }
            switch (current_lever) {
                case 0:
                    lever_P_init();
                    break;
                case 1:
                    lever_N_init();
                    break;
                case 2:
                    lever_D_init();
                    break;    
                case 3:
                    lever_R_init();
                    break;
            }
            
            print_data[0] = fnd1[current_lever];
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
