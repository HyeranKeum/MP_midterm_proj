#ifndef _MIDPj_SERVO_H_
#define _MIDPj_SERVO_H_

#include "hal_data.h"

extern const double SERVO_MINIMUM_DUTY; // 삭제 예정
extern const double SERVO_MAXIMUM_DUTY; // 삭제 예정
extern const double SERVO_EACH_DEGREE; // 삭제 예정

extern double temp_calc; // 삭제 예정
extern uint8_t degree;

void servo_initial();
void Rotate_Servo();
void calc_degree();

#endif 
