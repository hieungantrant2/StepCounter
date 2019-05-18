/*
 * lcd.h
 *
 *  Created on: May 13, 2019
 *      Author: Tran Hieu Ngan
 */

#ifndef LCD_LIB_LCD_H_
#define LCD_LIB_LCD_H_

#include <msp430.h>
#define lcd_delay   500
//Set PIN DATA
#define DDRLCD      P2DIR
#define PORTLCD     P2OUT
#define PINLCD      P2IN
#define PRENLCD     P2REN
#define PSELLCD     P2SEL
#define PSEL2LCD    P2SEL2
#define SHIFT_DATA  0       // vi tri dich trai so voi vi tri goc 0xF0
//Set PIN RS
#define DDR_RS      P2DIR
#define PORT_RS     P2OUT
#define PIN_RS      P2IN
#define RS          0x02
//Set PIN E
#define DDR_E       P2DIR
#define PORT_E      P2OUT
#define PIN_E       P2IN
#define E           0x08
//Set PIN RW
//#define DDR_RW      P2DIR
//#define PORT_RW     P2OUT
//#define PIN_RW      P2IN
//#define RW          0x04

/* Chon kieu hien thi tang/giam, shift hoac khong shift */
#define LCD_DEC_CUR_SHIFT_ON()  LCD_Command(0x05);
#define LCD_DEC_CUR_SHIFT_OFF() LCD_Command(0x04);
#define LCD_INC_CUR_SHIFT_ON()  LCD_Command(0x07);
#define LCD_INC_CUR_SHIFT_OFF() LCD_Command(0x06);  // khuyen khich su dung cach nay

/******************************************************************************\
*                   Prototype (nguyen mau ham)                                 *
\******************************************************************************/

void LCD_Init_write(unsigned char b);         //Ghi du lieu 8bit len lcd
void LCD_Command(unsigned char chr);      //ghi 2 nibbles vao lcd
char LCD_Read2Nib();
void LCD_Init();                              //khoi dong lcd
void LCD_Clear();                             //xoa lcd
void LCD_Home();
void LCD_Display(unsigned char chr);          //hien thi ki tu
void LCD_Goto(unsigned char row, unsigned char column);       /* Di chuyen con tro toi vi tri hang row, cot column */
/* Dich chuyen con tro sang trai(direct=0) hoac sang phai(direct=1) "step" vi tri */
void LCD_CursorShift(unsigned char direct, unsigned char step);
void LCD_PrintString(char *str);                /* In ra man hinh xau ki tu str[] */
/* In ra man hinh so nguyen n voi so cho hien thi bang length(chua ke vi tri cua dau) */
void LCD_PrintDecimal(long n, unsigned char length);
/* In ra man hinh so thuc x voi so cho hien thi = length, so chu so sau dau phay la coma */
void LCD_PrintUnDecimal(long n, unsigned char length);
void LCD_PrintFloat(float x, unsigned char length, unsigned char coma);




#endif /* LCD_LIB_LCD_H_ */
