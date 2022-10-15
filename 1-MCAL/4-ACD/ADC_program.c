/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:ADC      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
	/* select VREF = AVCC */
	CLR_BIT(ADC_u8_ADMUX_REG,7);
	SET_BIT(ADC_u8_ADMUX_REG,6);
	/* Right Adjustment */
	CLR_BIT(ADC_u8_ADMUX_REG,5);
	/* Single Conversion Mode */
	CLR_BIT(ADC_u8_ADCSRA_REG,5);
	/* Set Prescaler = CLK/64 */
	SET_BIT(ADC_u8_ADCSRA_REG,2);
	SET_BIT(ADC_u8_ADCSRA_REG,1);
	CLR_BIT(ADC_u8_ADCSRA_REG,0);
	/* ADC Enable */
	SET_BIT(ADC_u8_ADCSRA_REG,7);
}

u8 ADC_u8GetDigitalValue(u8 Copy_u8ChannelNum,u16* Copy_pu16ReturnedDigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNum <= 31)&&(Copy_pu16ReturnedDigitalValue != NULL))
	{
		/* Clear Channel Region */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/* Start Convertion */
		SET_BIT(ADC_u8_ADCSRA_REG,6);
		/* Wait For Flag */
		while(GET_BIT(ADC_u8_ADCSRA_REG,4)=0);// while(!GET_BIT(ADC_u8_ADCSRA_REG,4));
		/* Read digital Value */
		*Copy_pu16ReturnedDigitalValue = ADC_u16_ADC_REG;

	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
