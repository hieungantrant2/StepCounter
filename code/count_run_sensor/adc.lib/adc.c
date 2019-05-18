#include<adc.lib/adc.h>
#include<msp430.h>


// library to get adc result from sensor

void adc_init(void)
{
    ADC10CTL0 = ADC10SHT_1 + ADC10ON + ADC10IE; //
    ADC10CTL1 = INCH_0+ ADC10SSEL_3 ;
    ADC10AE0 |= BIT0; //p1.1
}
int adc_tranfer(void)
{
    ADC10CTL0 |= ENC + ADC10SC ;
 //   _bis_SR_register(GIE);
    return ADC10MEM;
}
