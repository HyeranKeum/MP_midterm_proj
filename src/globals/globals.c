#include "hal_data.h"
#include "globals.h"

volatile uint32_t Toggle   = 0;
volatile uint32_t count = 0;

uint32_t Timer_Period = 0x249F00; // 20[ms] Duty Cycle (50[Hz])
