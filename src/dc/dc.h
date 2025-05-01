#ifndef	_MIDPj_DC_H_  
#define _MIDPj_DC_H_ 
#include "hal_data.h"
//DC
extern bsp_io_port_pin_t L293_CH0_Enable;
extern bsp_io_port_pin_t L293_CH0_Direction;
extern uint8_t L293_CH0_Enable_Level;
extern uint8_t L293_CH0_Direction_Level;
extern uint32_t Timer_Period;
void DC_initial();

#endif