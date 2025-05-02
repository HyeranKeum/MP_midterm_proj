#include "hal_data.h"
#include "globals.h"
#include "dc/dc.h"
#include "servo/servo.h"

volatile uint32_t Toggle   = 0;
volatile uint32_t count = 0;

uint32_t Timer_Period = 0x249F00; // 20[ms] Duty Cycle (50[Hz])

volatile Lever_mode current_lever = 0;

void LED_inital() {
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_HIGH); // PA08
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_09, BSP_IO_LEVEL_HIGH); // PA09
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, BSP_IO_LEVEL_HIGH); // PA10
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, BSP_IO_LEVEL_HIGH); // PB00
}

void lever_P_init(){
    current_lever = P;
    DC_initial(); // (debug)시계반대방향, count stop
    servo_initial(); // dutyRate 0, count stop
}

void lever_N_init(){
    current_lever = N;
    R_GPT0->GTCR_b.CST = 1U; // Servo Start
}

void lever_D_init(){
    current_lever = D;
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_LOW); // PA08
    R_GPT3->GTCR_b.CST = 1U; // DC Start
}

void lever_R_init(){
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_HIGH); // PA08
    current_lever = R;
}