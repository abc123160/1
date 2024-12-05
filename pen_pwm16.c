#include "pwm16.h"

void pwm16Init()
{
    // Set PORTB5 (OC0A) as output
    DDRE |= (1<<PORTE3);  //OC3A fast PWM output

    TCCR3A |= (1<<COM3A1) | (1<<WGM31) ;
    TCCR3B |= (1<<WGM32)  | (1<<WGM33) |  (1<<CS31) | (1<<CS30);  // Counter fast PWM mode
    ICR3 = 4999; //Set Top Overflow
}

void pwm16Run(uint16_t duty)
{
   OCR3A =duty;
}