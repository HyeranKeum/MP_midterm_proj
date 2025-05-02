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

typedef struct {
    uint8_t gear;
    char display_char;
    uint8_t duty_low;
    uint8_t duty_high;
} Gear;
extern volatile Gear current_gear;

extern const Gear gear_0; // 모드P일 때
extern const Gear gear_1;
extern const Gear gear_2;
extern const Gear gear_3;
extern const Gear gear_4;

extern uint8_t percent_ptio;

extern volatile bool Error;

void initial_setting();

void LED_inital();

void system_on();

void lever_P_init();
void lever_N_init();
void lever_D_init();
void lever_R_init();

void mode_init();

void set_gear();

void detect_error();

#endif 