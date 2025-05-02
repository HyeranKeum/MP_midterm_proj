#include "hal_data.h"
#include "../globals/globals.h"
#include "../uart/uart.h"
#include "agt.h"

char message[5];
const char lever_char_table[4] = { 'P', 'N', 'D', 'R' };
const char mode_char_table[2] = { 'A', 'M' };

volatile int agt_test = 0;

void AGT0_init() {
    R_AGT_Open(&Error_timer_ctrl, &Error_timer_cfg);
    R_AGT_Enable(&Error_timer_ctrl);
    
}

void R_AGT0_Interrupt(timer_callback_args_t *p_args) {

    FSP_PARAMETER_NOT_USED(p_args);

    if (!Error) {
        return;
    }

    agt_test += 1;

    message[0] = lever_char_table[current_lever];
    message[1] = mode_char_table[current_mode];
    message[2] = current_gear.display_char;
    message[3] = '\0';

    user_uart_write(message, strlen(message)); // PNDR, a/m, gear

}
