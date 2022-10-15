/*
 * main.c
 *
 *  Created on: Sep 30, 2021
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

void main()
{
	/* Initialize Lcd Pins Direction */

	DIO_voidInit();
	LCD_VoidInit();

	while(1)
	{
	    /* frame 1 */
		LCD_VoidGoToXY(0,1);
		LCD_ViodSendString("Hallo Iam Abdo");
		u8 pattern1[8]={0b00000100,0b00001010,0b00000101,0b00001110,0b00001100,0b00000100,0b00001010,0b00000000};
		u8 pattern2[8]={0b00000100,0b00001010,0b00000100,0b00001111,0b00001100,0b00000100,0b00001010,0b00000000};

		u8 i=0;
		while(i<3)
		{
			LCD_voidWriteSpecialCharacter(pattern1,0,1,7);
			_delay_ms(300);
			LCD_voidWriteSpecialCharacter(pattern2,1,1,7);
			_delay_ms(300);
			i++;
		}
		_delay_ms(300);
		LCD_voidClear();
		/* frame 2 */
		u8 pattern3[8]={0b00000100,0b00001010,0b00000100,0b00011111,0b00000111,0b00000100,0b00001010,0b00000000};
		u8 pattern4[8]={0b00001000,0b00010100,0b00001000,0b00001000,0b00011100,0b00001000,0b00010101,0b00000000};
		u8 pattern5[8]={0b00000100,0b00001010,0b00000100,0b00000100,0b00001110,0b00000100,0b00001010,0b00000000};
		u8 pattern6[8]={0b00000100,0b00001010,0b00000100,0b00000100,0b00001100,0b00000100,0b00001011,0b00000000};
		u8 pattern7[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000010,0b00000000,0b00000000,0b00000000};
		u8 pattern8[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000010,0b00000000};



		LCD_voidWriteSpecialCharacter(pattern3,2,1,7);
		LCD_VoidGoToXY(0,1);
		LCD_ViodSendString("I Love Football");
		_delay_ms(2000);
		LCD_voidClear();

		LCD_voidWriteSpecialCharacter(pattern4,3,1,1);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);

		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("Hey Guys!!");
		_delay_ms(2000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern4,3,1,1);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("I have a ball");
		_delay_ms(2000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern4,3,1,1);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("Let's Play");
		_delay_ms(2000);
		LCD_voidClear();

		LCD_voidWriteSpecialCharacter(pattern4,3,1,1);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_VoidGoToXY(0,13);
		LCD_ViodSendString("Ok");
		_delay_ms(2000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern4,3,1,1);
		LCD_VoidGoToXY(0,3);
		LCD_ViodSendString("pass the ball");
		_delay_ms(2000);
		LCD_voidClear();
		//abdo pass the ball
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern4,3,1,1);
		_delay_ms(1000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern6,5,1,1);
		_delay_ms(1000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,1);
		LCD_voidWriteSpecialCharacter(pattern7,6,1,2);
		_delay_ms(1000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,1);
		LCD_voidWriteSpecialCharacter(pattern7,6,1,3);
		_delay_ms(350);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,1);
		LCD_voidWriteSpecialCharacter(pattern7,6,1,4);
		_delay_ms(350);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,1);
		LCD_voidWriteSpecialCharacter(pattern8,7,1,5);
		_delay_ms(350);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,1);
		LCD_voidWriteSpecialCharacter(pattern8,7,1,5);
		LCD_VoidGoToXY(0,3);
		LCD_ViodSendString("Be goalkeeper");
		_delay_ms(2000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,1);
		LCD_voidWriteSpecialCharacter(pattern8,7,1,5);
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("No!!");
		_delay_ms(2000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern3,2,1,5);
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("It's my ball!");
		_delay_ms(2000);
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(pattern3,2,1,5);
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("I Will Leave");
		_delay_ms(2000);
		LCD_voidClear();
		u8 let1[8]={0b00000001,0b00000001,0b00000001,0b00000001,0b00011101,0b00010100,0b00011100,0b00000000};
		u8 let2[8]={0b00000100,0b00000100,0b00000100,0b00000100,0b00011111,0b00000000,0b00000000,0b00000000};
		u8 let3[8]={0b00000011,0b00000010,0b00000011,0b00000100,0b00000111,0b00000000,0b00000000,0b00000000};
		u8 let4[8]={0b00000101,0b00000101,0b00000101,0b00000101,0b00011101,0b00010000,0b00010000,0b00000000};
		u8 let5[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000100,0b00000100,0b00000111,0b00000000};
		u8 let6[8]={0b00000000,0b00000000,0b00010110,0b00010001,0b00011111,0b00000000,0b00000010,0b00000000};
		u8 let7[8]={0b00000000,0b00000000,0b00000100,0b00000100,0b00011111,0b00000000,0b00001011,0b00000000};
		u8 let8[8]={0b00000000,0b00000110,0b00001111,0b00000111,0b00011111,0b00000000,0b00000000,0b00000000};
		u8 let9[8]={0b00000101,0b00000101,0b00000101,0b00000101,0b00011101,0b00000000,0b00000000,0b00000000};
		u8 let10[8]={0b00001101,0b00001001,0b00011101,0b00010001,0b00011111,0b00000000,0b00000000,0b00000000};

        LCD_voidWriteSpecialCharacter(pattern5,4,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,4,1,12);
		LCD_voidWriteSpecialCharacter(let1,0,0,15);
		LCD_voidWriteSpecialCharacter(let2,1,0,14);
		LCD_voidWriteSpecialCharacter(let3,2,0,13);
		_delay_ms(1000);
		LCD_voidClear();
        LCD_voidWriteSpecialCharacter(pattern5,0,1,14);
		LCD_voidWriteSpecialCharacter(pattern5,0,1,12);
		LCD_voidWriteSpecialCharacter(let4,1,0,15);
		LCD_voidWriteSpecialCharacter(let5,2,0,14);
		LCD_voidWriteSpecialCharacter(let6,3,0,13);
		LCD_voidWriteSpecialCharacter(let7,4,0,12);
		LCD_voidWriteSpecialCharacter(let8,5,0,11);
		LCD_voidWriteSpecialCharacter(let9,6,0,10);
		LCD_voidWriteSpecialCharacter(let10,7,0,9);
		_delay_ms(5000);
		LCD_voidClear();



	}

}

