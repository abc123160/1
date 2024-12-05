#include "ap.h"

char rxBuff[100] = {0};
uint8_t rxFlag ;

void apInit()
{

}

void apMain (void)
{
    // LED led;
    // led.port= &PORTB;
    // led.pin=0;

    // ledInit(&led);

    // Button btnOn;
    // Button btnOff;
    // Button btnTog;

    // buttonInit(&btnOn,&BUTTON_DDR,&BUTTON_PIN,BUTTON_ON);
    // buttonInit(&btnOff,&BUTTON_DDR,&BUTTON_PIN,BUTTON_OFF);
    // buttonInit(&btnTog,&BUTTON_DDR,&BUTTON_PIN,BUTTON_TOGGLE);

    // pwm8Init();
    // pwm16Init();
    // uart0Init();

    // extern FILE OUTPUT;

    // stdout = &OUTPUT;
    // LCD_Init();
    // LCD_WriteStringXY(0,0,"Hello ATmega128a");

    // uint16_t count = 0;
    // uint16_t count = buff[30];

    // timeInit();
    // uint8_t distance;

    while(1)
    {   
        // triggerPin();
        // distance = mean();
        // print("distnace : %d cm\r\n", distance);
        // _delay_ms(500);


        // LCD_WriteString(1,0,buff);
        // _delay_ms(100);

        OCR3A = 125;
        _delay_ms(1000);

        OCR3A = 590;
        _delay_ms(1000);


        if(rxFlag == 1)     //char 
        {
            rxFlag  = 0;
            printf(rxBuff); 
        }

        uart0Receive();

        led.pin


        /*
        for(uint8_t i =0; i<8; i++)
        {
            ledInit(&led);
            led.pin=i;
            ledOn(&led);
            _delay_ms(100);
            ledOff(&led);
            _delay_ms(100);
        }*/
        //pwm8Run(50);
        /*
        if(Button_getState(&btnOn) == ACT_RELEASE)
        {
            ledOn(&led);
            pwm8Run(200);

        }
        if(Button_getState(&btnOff) == ACT_RELEASE)
        {
            ledOff(&led);
            pwm8Run(0);
        }
        if(Button_getState(&btnToggle) == ACT_RELEASE)
        {
            ledToggle(&led);
        }
        */
        OCR3A = 125;
        _delay_ms(1000);

        OCR3A = 590;
        _delay_ms(1000);

        uart0Transmit(uart0Receive());

    }

    

}