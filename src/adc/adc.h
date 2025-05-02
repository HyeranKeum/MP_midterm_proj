#ifndef _MIDPj_ADC_H_
#define _MIDPj_ADC_H_

#include "hal_data.h"

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

void ADC_initial();
void Potentiometer_Read();
void Cds_Sensor_Read();
void ADC_Read_and_Convert(void);

#endif