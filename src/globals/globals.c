#include "hal_data.h"
#include "globals.h"

volatile uint32_t Toggle   = 0;
volatile uint32_t count = 0;

uint16_t potentiometer_mV = 0, potentiometer_Ra = 0, potentiometer_Rb = 0;
CDS_t brightness;
uint16_t cds_data;

const float ADC_CONST = (float)(3.3/4096);

uint32_t Timer_Period = 0x249F00; // 20[ms] Duty Cycle (50[Hz])
