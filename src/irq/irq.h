#ifndef _MIDPj_IRQ_H_
#define _MIDPj_IRQ_H_
#include "hal_data.h"

void IRQ_Setting();

extern volatile bool SW3_interrupt;
extern volatile bool SW4_interrupt;
#endif