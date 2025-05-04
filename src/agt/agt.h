#ifndef _MIDPj_AGT_H_
#define _MIDPj_AGT_H_

#include "hal_data.h"

extern const char char_table_lever[4]; // 삭제 예정 ? 
extern const char char_table_mode[2];
extern char message[5];

void AGT_init();
void R_AGT0_Interrupt(timer_callback_args_t *p_args);

#endif
