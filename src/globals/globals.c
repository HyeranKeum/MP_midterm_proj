#include "hal_data.h"
#include "globals.h"
#include "dc/dc.h"
#include "irq/irq.h"
#include "fnd/fnd.h"
#include "adc/adc.h"
#include "servo/servo.h"

volatile uint32_t Toggle   = 0;
volatile uint32_t count = 0;

uint32_t Timer_Period = 0x249F00; // 20[ms] Duty Cycle (50[Hz])

volatile Lever_mode current_lever = 0;
volatile Mode current_mode = 0;

void initial_setting() {
    LED_inital();
    IRQ_Setting();
    DC_initial(); // 반시계방향 disable
    servo_initial();
    ADC_initial();

    R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);

    FND_initial();
}

void LED_inital() {
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_HIGH); // PA08
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_09, BSP_IO_LEVEL_HIGH); // PA09
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, BSP_IO_LEVEL_HIGH); // PA10
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, BSP_IO_LEVEL_HIGH); // PB00
}

void system_on(){
    lever_P_init();
    mode_init();
}

void lever_P_init(){
    current_lever = P;
    DC_initial(); // 시계방향, disable
    servo_initial(); // degree 0, count stop
}

void lever_N_init(){
    current_lever = N;
    R_GPT0->GTCR_b.CST = 1U; // Servo Start
}

void lever_D_init(){
    current_lever = D;
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_LOW); // PA08
    // R_GPT3->GTCR_b.CST = 1U; // DC Start
    R_GPT3->GTCR_b.CST = 1U;
    L293_CH0_Enable_Level = BSP_IO_LEVEL_HIGH;
    R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Enable, L293_CH0_Enable_Level);

}

void lever_R_init(){
    current_lever = R;
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_HIGH); // PA08

    L293_CH0_Direction_Level = BSP_IO_LEVEL_LOW; // 반시계방향
    R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
}

void mode_init(){ // auto(current_mode = 0) <-> manual(current_mode = 1) 토글 시 
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_09, current_mode); // PA09
}
