#ifndef _MIDPj_SERVO_H_
#define _MIDPj_SERVO_H_

#include "hal_data.h"

extern const double SERVO_MINIMUM_DUTY;
extern const double SERVO_MAXIMUM_DUTY;
extern const double SERVO_EACH_DEGREE;

extern double temp_calc;
extern uint8_t degree;

void servo_initial();
void Rotate_Servo();

#endif 
