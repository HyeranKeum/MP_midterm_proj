#include "hal_data.h"
#include "fnd.h"

uint8_t number[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90};
uint8_t print_data[4] = {0xC0, 0xC0, 0xC0, 0xC0};

int f1 = 0, f2 = 0, f3 = 0, f4 = 0;

uint8_t fnd1[4] = {
    0x8C,  // P
    0xAB,  // N : c, e, g
    0xA1,  // D : b, c, d, e, g
    0xAF   // R : e, g
};

uint8_t fnd2[2] = {
    0x88,  // A
    0x83   // B
};

uint8_t fnd3[5] = {
    0xBF,  // '-' (P 상태)
    0xF9,  // 1
    0xA4,  // 2
    0xB0,  // 3
    0x99   // 4
};

uint8_t fnd4[2] = {
    0xFF,  // 정상 (표시 없음)
    0x86   // E
};
void FND_initial() {
    print_data[0] = fnd1[(f1)];
    print_data[1] = fnd2[(f2)];
    print_data[2] = fnd3[(f3)];
    print_data[3] = fnd4[(f4)];
    R_FND_Reset();
}

void R_FND_Reset()
{
    /* 7-Segment LED Pin State Initialization */
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

    // uint16_t key = 0; idx = 0;

    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);
    R_FND_Reset();

    R_PORT3->PCNTR1_b.PODR = 1U << (digit + 5U);

    /* 7-Segment LED Pin State Setting */
    R_PORT6->PCNTR1_b.PODR = (uint16_t)(((data & 0xf0) << 7U) | ((data & 0x0f) << 4U));

}
