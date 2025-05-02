#ifndef _MIDPj_FND_H_
#define _MIDPj_FND_H_

#include "hal_data.h"
#define SEGMENT_INDEX         8
#define DIGIT_INDEX           4

#define PODR_INDEX_HIGH       7
#define PODR_INDEX_LOW        4
#define PODR_DIGIT_MASK       0x01E0
#define PODR_HIGH_MASK        0x7800
#define PODR_LOW_MASK         0x00F0
#define PODR_PIN_MASK         PODR_HIGH_MASK | PODR_LOW_MASK

extern uint8_t number[10];
extern uint8_t print_data[4];

extern int f1, f2, f3, f4;

extern uint8_t fnd1[4];

extern uint8_t fnd2[2];

extern uint8_t fnd3[5];

extern uint8_t fnd4[2];

extern void R_FND_Reset();

extern void R_FND_Print_Data(uint8_t *string);

extern void R_FND_Display_Data(uint8_t digit, uint8_t data);

extern void FND_initial();

#endif 