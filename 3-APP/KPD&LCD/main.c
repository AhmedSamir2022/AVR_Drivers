/*
 * main.c
 *
 *  Created on: Oct 12, 2021
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#define  F_CPU  8000000UL
#include <avr/delay.h>

void main()
{
	DIO_voidInit();
	LCD_VoidInit();
	u8 Local_u8Password[4]={1,2,3,4};
	u8 Local_Au8Value[4];
	u8 Local_u8Temp;
	while(1)
	{
		LCD_VoidGoToXY(0,0);
		LCD_ViodSendString("Enter Password:");
		KPD_u8GetKey(&Local_u8Temp);
		for(u8 u=0;u<3;u++)
		{
			for(u8 i=0;i<4 && Local_u8Temp != KPD_u8_NOT_PRESSED;i++)
			{
				LCD_VoidSendData('*');
				Local_Au8Value[i]=Local_u8Temp;
				_delay_ms(200);
			}
			if(Local_Au8Value[0]==Local_u8Password[0] && Local_Au8Value[1]==Local_u8Password[1] && Local_Au8Value[2]==Local_u8Password[2] && Local_Au8Value[3]==Local_u8Password[3])
			{
				LCD_voidClear();
				_delay_ms(200);
				LCD_ViodSendString("Hallo Ahmed..");
				break;
			}

		}
		if(Local_Au8Value[0]!=Local_u8Password[0] && Local_Au8Value[1]!=Local_u8Password[1] && Local_Au8Value[2]!=Local_u8Password[2] && Local_Au8Value[3]!=Local_u8Password[3])
		{
			LCD_voidClear();
			_delay_ms(200);
			LCD_ViodSendString("Fuck You..");
		}

	}
}
