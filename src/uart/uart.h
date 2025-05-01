#ifndef _MIDPj_UART_H_
#define _MIDPj_UART_H_

#include "hal_data.h"
//UART
#define MESSAGE_MAX_SIZE     10
#define CARRIAGE_RETURN      0x0D
#define LINE_FEED            0x0A

extern char tail[2];

void user_uart_callback();
void user_uart_write();
#endif