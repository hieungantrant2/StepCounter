


#include <msp430.h> 
#include <stdint.h>
#include"adc.lib/adc.h"
#include "uart.lib/uart.h"

/**
 * main.c
 */
unsigned char step_run(void);
int sensor=65,adc;
unsigned char number_step;// sensor can be 265
void main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	DCOCTL = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;
	uart_init();
	adc_init();//p1.0
while(1)
{
    number_step = step_run();
   // adc =  adc_tranfer();
    uart_pushchar(number_step);
    _delay_cycles(10);
}

}
unsigned char step_run(void)
{
 unsigned char static k=0;
 uint16_t   adc_before,adc;// pass the fist k alway increa 1
 adc_before=adc;
 adc=adc_tranfer();
 if((adc>(adc_before+sensor*5))||(adc<(adc_before-sensor*5)))
{
     k++;
}
 return k;
}
#pragma vector = USCIAB0RX_VECTOR
__interrupt void UCA0RX_ISR(void)
{
    sensor = UCA0RXBUF;
    IFG2 &= ~UCA0RXIFG;
}
