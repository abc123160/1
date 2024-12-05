#include "common/def.h"
#include ""

void UART_init(unsigned int baud);
void UART_transmit(char data);

char UART_receive();