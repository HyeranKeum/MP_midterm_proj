#include "hal_data.h"
#include "../globals/globals.h"
#include "fnd.h"

uint8_t print_data[4] = {0xC0, 0xC0, 0xC0, 0xC0};

uint8_t fnd1[4] = {
    0x8C,  // P
    0xAB,  // N : c, e, g
    0xA1,  // D : b, c, d, e, g
    0xAF   // R : e, g
};

uint8_t fnd2[2] = {
    0x88,  // A
    0x83   // b
};

uint8_t fnd3[5] = {
    0xBF,  // '-' (P 상태)
    0xF9,  // 1
    0xA4,  // 2
    0xB0,  // 3
    0x99   // 4
};

uint8_t fnd4[2] = {
    0xFF,  // (표시 없음)
    0x86   // E
};

void FND_initial() {
    print_data[0] = fnd1[0];
    print_data[1] = fnd2[0];
    print_data[2] = fnd3[0];
    print_data[3] = fnd4[0];
    R_FND_Reset();
}

void R_FND_Reset()
{
    R_PORT3->PCNTR1_b.PODR &= ~PODR_DIGIT_MASK & 0xFFFF;
    R_PORT6->PCNTR1_b.PODR |= PODR_PIN_MASK;
}

void R_FND_Print_Data(uint8_t *string)
{
    uint8_t idx = 0;

    if (sizeof(string) != DIGIT_INDEX)
        return;

    for (idx = 0; idx < DIGIT_INDEX; idx++){
        R_FND_Display_Data(idx, string[idx]);
    }
}

void R_FND_Display_Data(uint8_t digit, uint8_t data)
{

    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);
    R_FND_Reset();

    R_PORT3->PCNTR1_b.PODR = 1U << (digit + 5U);

    R_PORT6->PCNTR1_b.PODR = (uint16_t)(((data & 0xf0) << 7U) | ((data & 0x0f) << 4U));

}

void fnd_print_state(){ // 현재 상태 fnd 출력
    print_data[0] = fnd1[current_lever];
    print_data[1] = fnd2[current_mode];
    print_data[2] = fnd3[current_gear.gear];
    print_data[3] = fnd4[Error];
    R_FND_Print_Data(print_data);
}