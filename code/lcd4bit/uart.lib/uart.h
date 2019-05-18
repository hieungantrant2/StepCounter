/*
 * uart.h
 *
 *  Created on: May 14, 2019
 *      Author: Tran Hieu Ngan
 */

#ifndef UART_LIB_UART_H_
#define UART_LIB_UART_H_

void uart_init();
void uart_pushtext(char c);
void uart_pushstring(char *string);
int uart_recieve();


#endif /* UART_LIB_UART_H_ */
