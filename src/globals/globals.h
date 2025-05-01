#ifndef _MIDPj_GLOBALS_H_ 
#define _MIDPj_GLOBALS_H_

#include "hal_data.h"

extern uint32_t Timer_Period;

extern volatile uint32_t dutyRate;
extern volatile uint32_t Toggle;

extern volatile uint32_t count;

extern uint16_t potentiometer_mV;
extern uint16_t potentiometer_Ra;
extern uint16_t potentiometer_Rb;
extern uint16_t cds_data;

typedef enum {
    CDS_light = 0,
    CDS_dark = 1,
}CDS_t;

extern CDS_t brightness;

extern const float ADC_CONST;
#endif 