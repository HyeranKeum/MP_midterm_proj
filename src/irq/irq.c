#include "hal_data.h"
#include "../globals/globals.h"
#include "../dc/dc.h"
#include "../servo/servo.h"
#include "../fnd/fnd.h"
#include "irq.h"

bool volatile SW3_interrupt;
bool volatile SW4_interrupt;

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
            
            break;
        }
        case 12: {
            current_mode ^= 0x01; // 모드 토글
            mode_init();
            break;
        }
        case 13: { // gear up
            if ((current_mode == Auto) || (current_lever == P) || (current_gear.gear == 4)){
                return;
            }
            current_gear = gear_list[current_gear.gear + 1];
            R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, BSP_IO_LEVEL_LOW); // PA10
            SW3_interrupt = true;
            break;
        }
        case 14: {
            if ((current_mode == Auto) || (current_lever == P) || (current_gear.gear == 1)){
                return;
            }
            current_gear = gear_list[current_gear.gear - 1];
            R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, BSP_IO_LEVEL_LOW); // PB00
            SW4_interrupt = true;
            break;
        }
    }
}
