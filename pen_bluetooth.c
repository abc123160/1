#include <avr/io.h>
#include <util/delay.h>

void UART_init(unsigned int baud)           //  20.USART
{
    UBRR0H = (unsigned char)(baud >> 8);    // Set baud rate high byte
    UBRR0L = (unsigned char)baud;           // Set baud rate low byte
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);   // Enable RX and TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit
}

void UART_transmit(char data)
{
    while (!(UCSR0A & (1 << UDRE0))); // Wait for empty transmit buffer
    UDR0 = data;                      // Send data
}

char UART_receive() 
{
    while (!(UCSR0A & (1 << RXC0))); // Wait for data to be received
    return UDR0;                     // Return received data
}

int main() 
{
    UART_init(103);                  // Baud rate = 9600 (assuming 16MHz clock)
    char received;

    while (1) {
        received = UART_receive();   // Receive data from Bluetooth
        UART_transmit(received);     // Echo received data back
    }
}