#include "dc.h"
#include "../globals/globals.h"
#include "../adc/adc.h"
#include "hal_data.h"

//DC
bsp_io_port_pin_t L293_CH0_Enable = BSP_IO_PORT_09_PIN_00;
bsp_io_port_pin_t L293_CH0_Direction = BSP_IO_PORT_09_PIN_01;
uint8_t L293_CH0_Enable_Level = BSP_IO_LEVEL_LOW;
uint8_t L293_CH0_Direction_Level;
volatile uint32_t dutyRate = 0;
uint32_t tmp_dutyRate = 0;

void calc_dutyRate();
void Rotate_DC();

void DC_initial(){
    R_MSTP->MSTPCRD_b.MSTPD5 = 0U; // GPT32EH3 Module Stop State Cancel

    R_GPT3->GTCR_b.MD = 0U; // GPT32EH3 Count Mode Setting (Saw-wave PWM Mode)
    R_GPT3->GTCR_b.TPCS = 0U; // GPT32EH3 Clock Source Pre-scale Setting (PCLKD/1)

    R_GPT3->GTPR = Timer_Period - 1; // GPT32EH3 Counting Maximum Cycle Setting
    R_GPT3->GTCNT = 0; // GPT32EH3 Counter Initial Value Setting

    R_GPT3->GTIOR_b.GTIOA = 9U; // Compare Matching Output Control Setting
    R_GPT3->GTIOR_b.OAE = 1U; // GPIOCA Output Pin Enable

    L293_CH0_Direction_Level = BSP_IO_LEVEL_HIGH; // 시계방향
    R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);

    R_GPT3->GTCCR[0] = Timer_Period; // GTCCR Initial Setting (Angle = 0[degree])

    R_GPT3->GTCR_b.CST = 0U;
    
    L293_CH0_Enable_Level = BSP_IO_LEVEL_LOW;
    R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Enable, L293_CH0_Enable_Level);
}

void calc_dutyRate() {
    tmp_dutyRate = TPS; // calc_TPS()에서 TPS 업데이트
    // 현재 기어 따라 dc 상하한 제한
    if (tmp_dutyRate < current_gear.duty_low) {
        tmp_dutyRate = current_gear.duty_low;
    }
    else if (tmp_dutyRate > current_gear.duty_high) {
        tmp_dutyRate = current_gear.duty_high;
    }

    if (current_lever == D){ // DC 시계 방향에서 dutyRate(%) 반대로 작동
        dutyRate = 100 - tmp_dutyRate;
        return;
    }
    dutyRate = tmp_dutyRate;
    
}

void Rotate_DC()
{
    R_GPT3->GTCCR[0] = Timer_Period * dutyRate / 100;
}

void set_dc()
 {
    calc_dutyRate();
    Rotate_DC();
 }