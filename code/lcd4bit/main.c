#include <msp430.h> 
#include"lcd.lib/lcd.h"
#include"adc.lib/adc.h"
#include "uart.lib/uart.h"
unsigned int step;
 void main(void)
{
    unsigned int  adc,adc_before;

         // float y=1.234;
          WDTCTL = WDTPW | WDTHOLD;  //Stop Watchdog
          DCOCTL = CALDCO_1MHZ;             // Clock=1Mhz
          BCSCTL1 = CALBC1_1MHZ;
          P1SEL &= ~BIT4;
          P1SEL2 &= ~BIT4;
          P1DIR |= BIT4;
          P1OUT &= ~BIT4;
          adc_init();
          uart_init();


          LCD_Init();
          LCD_Clear();
          while(1)
          {
            //  while((IFG2&UCA0RXIFG));
              adc = adc_tranfer();
              if(adc_before!= adc)
              {
                  adc_before = adc;
                  uart_pushchar(adc);
              }

              LCD_Home();
              LCD_PrintString("do nhay:");
              LCD_PrintDecimal(adc_before,4);
              //**if (st)
              LCD_Goto(2,0);
              LCD_PrintString("so buoc:");
              LCD_PrintDecimal(step,7);

//
//                 //LCD_Goto(2,8);
//                // LCD_PrintFloat(y,5,3);
                 _delay_cycles(100);
          }

}
// int uart_recieve()
// {
//     int k;
//
//
//
//     return k;
// }
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIA0TX_ISR(void)
{
    step = UCA0RXBUF;
    IFG2 &= ~UCA0RXIFG;
}
