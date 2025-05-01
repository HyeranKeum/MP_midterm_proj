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
    static char string[MESSAGE_MAX_SIZE]; // 정적 배열 사용
    memset(string, 0, sizeof(string)); // 이전 값 초기화

    strcpy(string, msg);
    strcat(string, tail);

    R_SCI_UART_Write(&g_uart0_ctrl, (unsigned char*)string, bytes + 2);
}