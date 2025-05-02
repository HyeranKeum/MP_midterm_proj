#ifndef _MIDPj_AGT_H_
#define _MIDPj_AGT_H_

#include "hal_data.h"

extern const char lever_char_table[4];
extern const char mode_char_table[2];
extern char message[5];
extern volatile int agt_test;

void AGT0_init();
void R_AGT0_Interrupt(timer_callback_args_t *p_args);

#endif
