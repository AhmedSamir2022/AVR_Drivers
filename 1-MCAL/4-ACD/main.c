/*
 * main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
void main(void)
{
	u16 Local_u16DigitalValue,Local_u16AnalogValue;
	/* Dio Init */
	DIO_voidInit();
	/* ADC Init */
	ADC_voidInit();
	while(1)
	{
		/* Get Digital Value */
		ADC_u8GetDigitalValue(0,&Local_u16DigitalValue);
		/* Calculate Analog Value = DV * step size */
		Local_u16AnalogValue = (Local_u16DigitalValue * 5000UL)/1024;
		if(Local_u16AnalogValue < 1500)
		{
			/*Turn on Led1*/
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);
		}
		else if(Local_u16AnalogValue >= 1500 && Local_u16AnalogValue < 3000)
		{
			/* Turn on Led2 */
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);
		}
		else if(Local_u16AnalogValue >= 3000)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
		}

	}
}

