#ifndef _MIDPj_GLOBALS_H_ 
#define _MIDPj_GLOBALS_H_

#include "hal_data.h"

extern uint32_t Timer_Period;

extern volatile uint32_t Toggle;

extern volatile uint32_t count;

typedef enum {
    P = 0,
    N = 1,
    D = 2,
    R = 3
}Lever_mode;
extern volatile Lever_mode current_lever;

typedef enum {
    Auto = 0,
    Manual
} Mode;
extern volatile Mode current_mode;

void initial_setting();

void LED_inital();

void system_on();

void lever_P_init();
void lever_N_init();
void lever_D_init();
void lever_R_init();

void mode_init();

#endif 