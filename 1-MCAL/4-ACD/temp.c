/*
 * temp.c
 *
 *  Created on: Oct 22, 2021
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

int main(void)
{
	u16 Local_u16DigitalValue,Local_u16AnalogValue;
	u16 Local_u8TempValue;
	/* Dio Init */
	DIO_voidInit();
	/* ADC Init */
	ADC_voidInit();
	while(1)
	{
		/* Get Digital Value */
		ADC_u8GetDigitalValue(0,&Local_u16DigitalValue);
		/* Calculate Analog Value = DV * step size */
		Local_u16AnalogValue = (Local_u16DigitalValue * 2560UL)/1024;
		Local_u8TempValue=Local_u16AnalogValue/10;
		if(Local_u8TempValue<10)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		else if(Local_u8TempValue<10)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_HIGH);
		}
	}
	return 0;
}

