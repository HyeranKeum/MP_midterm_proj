#include "hal_data.h"
#include "uart.h"

//UART
char tail[2] = {CARRIAGE_RETURN, LINE_FEED};

void user_uart_callback(uart_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    return;
}

void user_uart_write(const char *msg, uint32_t const bytes)
{
    char *string = (char*)calloc(1, sizeof(char) * MESSAGE_MAX_SIZE);

    strcpy(string, msg);
    strcat(string, tail);

    R_SCI_UART_Write(&g_uart0_ctrl, (unsigned char*)string, bytes + 2);

    free(string);
}   
