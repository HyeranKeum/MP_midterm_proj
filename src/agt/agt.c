#include "hal_data.h"
#include "../globals/globals.h"
#include "../uart/uart.h"
#include "../irq/irq.h"
#include "agt.h"

char message[5];
const char char_table_lever[4] = { 'P', 'N', 'D', 'R' };
const char char_table_mode[2] = { 'A', 'M' };

volatile int SW3_interrupt_count = 0;
volatile int SW4_interrupt_count = 0;

void AGT_init() {
    R_AGT_Open(&Error_timer_ctrl, &Error_timer_cfg); // AGT0(1s)
    R_AGT_Start(&Error_timer_ctrl);

    R_AGT_Open(&Switch_timer_ctrl, &Switch_timer_cfg); // AGT1(100ms)
    R_AGT_Start(&Switch_timer_ctrl);

}

void R_AGT0_Interrupt(timer_callback_args_t *p_args) {// AGT0(1s)

    FSP_PARAMETER_NOT_USED(p_args);
    // detectError()에서 Error 감지 시 UART 메시지 출력
    if (Error) {
        message[0] = char_table_lever[current_lever]; // P, N, D, R
        message[1] = char_table_mode[current_mode]; // A, M
        message[2] = current_gear.display_char; // -, 1, 2, 3, 4
        message[3] = '\0';

        user_uart_write(message, strlen(message)); // PNDR, A/M, gear
    }

}

void R_AGT1_Interrupt(timer_callback_args_t *p_args) {// AGT1(100ms)

    FSP_PARAMETER_NOT_USED(p_args);
    // 스위치 3, 4 눌린 후 LED 1초 후 끄기
    if (SW3_interrupt) {
        SW3_interrupt_count += 1;
        if (SW3_interrupt_count == 10) {
            SW3_interrupt = false;
            SW3_interrupt_count = 0;
            R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, BSP_IO_LEVEL_HIGH); // PA10
        }
    }

    if (SW4_interrupt) {
        SW4_interrupt_count += 1;
        if (SW4_interrupt_count == 10) {
            SW4_interrupt = false;
            SW4_interrupt_count = 0;
            R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, BSP_IO_LEVEL_HIGH); // PB00
        }

    }
}
