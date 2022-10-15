/*
 * main.c
 *
 *  Created on: Dec 10, 2021
 *      Author: DELL
 */
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <avr/delay.h>

#include "DIO_interface.h"
#include "EEP_interface.h"

#define PASS_SIZE     10

#define SWITCHS_PORT  PINA
#define SW0           0
#define SW1           1
#define SW2           2

void main()
{
	DIO_voidInit();
	EEPROM_Init();

	u8 password[PASS_SIZE]="";
	u8 userPassword[PASS_SIZE]="";
	u8* temp=userPassword;

	while(1)
	{

		while(GET_BIT(SWITCHS_PORT,SW2)!=0)
		{
			if(!GET_BIT(SWITCHS_PORT,SW0))
			{
				_delay_ms(2000);
				if(!GET_BIT(SWITCHS_PORT,SW0))
				{
					*temp='1';
					temp++;
				}
				else
				{
					*temp='0';
					temp++;
				}

			}
		}

	}

}


if(GET_BIT(SWITCHS_PORT,SW0)==0)
			{
				*temp='0';
				temp++;
				DIO_u8TogPinValue(DIO_u8_PORTB,DIO_u8_PIN2);
				_delay_ms(500);

			}
			else if(GET_BIT(SWITCHS_PORT,SW1)==0)
			{
				*temp='1';
				temp++;
				DIO_u8TogPinValue(DIO_u8_PORTB,DIO_u8_PIN2);
				_delay_ms(500);
			}

