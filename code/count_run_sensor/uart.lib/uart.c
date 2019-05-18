/*
 * uart.c
 *
 *  Created on: May 14, 2019
 *      Author: Tran Hieu Ngan
 */
#include <msp430.h>
#include <stdint.h>
void uart_init()
{
UCA0CTL1 |= UCSSEL_2 | UCSWRST;

    UCA0BR1 = (uint8_t)((104)>>8);
    UCA0BR0 = (uint8_t)104;
    UCA0MCTL |= UCBRF0 | UCBRF1;

    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;

    UCA0CTL1 &=~ UCSWRST;
    IE2 = UCA0TXIE;
}
void uart_pushchar(char c)
{
    UCA0TXBUF = c;
    while(!(IFG2&UCA0TXIFG));
    IFG2 &= ~UCA0TXIFG;
}
void uart_pushstring(char *string)
{
    while(*string)
    {
        uart_pushchar(*string);
        string++;
    }

}
unsigned int uart_recieve()
{
    while(!(IFG2&UCA0RXIFG));
    return UCA0RXBUF;


}


