/*
 * main.c
 *
 *  Created on: Oct 2, 2021
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#define F_CPU   8000000UL
#include <avr/delay.h>
#define F_CPU   8000000UL

void main()
{
	DIO_u8SetPortDirection(DIO_u8_PORTC,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_OUTPUT);
	LCD_VoidInit();



	while(1)
	{
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("AHMED");

		u8 pattern1[8]={0b00000001,0b00000001,0b00011101,0b00000011,0b00011111,0b00000000,0b00000000,0b00000000};
		u8 pattern2[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00011111,0b00001010,0b00001110,0b00000000};
		u8 pattern3[8]={0b00000000,0b00000000,0b00000010,0b00000010,0b00001111,0b00000000,0b00000000,0b00000000};

		LCD_voidWriteSpecialCharacter(pattern1,0,1,2);
		LCD_voidWriteSpecialCharacter(pattern2,1,1,1);
		LCD_voidWriteSpecialCharacter(pattern3,2,1,0);
		_delay_ms(500);
		LCD_voidClear();

		LCD_VoidGoToXY(1,5);
		LCD_ViodSendString("AHMED");
		LCD_voidWriteSpecialCharacter(pattern1,0,0,7);
		LCD_voidWriteSpecialCharacter(pattern2,1,0,6);
		LCD_voidWriteSpecialCharacter(pattern3,2,0,5);
		_delay_ms(500);
		LCD_voidClear();

		LCD_VoidGoToXY(0,11);
		LCD_ViodSendString("AHMED");
		LCD_voidWriteSpecialCharacter(pattern1,0,1,13);
		LCD_voidWriteSpecialCharacter(pattern2,1,1,12);
		LCD_voidWriteSpecialCharacter(pattern3,2,1,11);
		_delay_ms(500);
		LCD_voidClear();


	}
}
