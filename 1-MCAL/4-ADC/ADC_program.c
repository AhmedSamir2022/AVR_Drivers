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
#include "ADC_register.h"

static u16* ADC_pu16Reading=NULL;
static void(*ADC_pvCallBackNotificationFunc)(void)=NULL;

u8 ADC_u8BusyState= IDLE;

void ADC_voidInit(void)
{
	/* AVCC as reference voltage */
	SET_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REF0);
	CLR_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REF1);

	/* Activate Left adjust result */
	SET_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_ADLR);

	/* Set Prescaler = CLK/64 */
	CLR_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADPS0);
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADPS1);
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADPS2);

	/* ADC Enable */
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADEN);

}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(ADC_u8BusyState == IDLE)
	{
		/* Make ADC busy */
		ADC_u8BusyState= BUSY;
		/* Clear the Mux bits in the ADMUX register */
		ADC_u8_ADMUX_REG &= 0b11100000;

		/* Set the required channel into the MUX bits */
		ADC_u8_ADMUX_REG |= Copy_u8Channel;

		/* Start conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADSC);

		/* Polling (busy waiting) until coversiion complete flag is set or counter reaching time out */
		while((GET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADIF)==0) && (Local_u32Counter != ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter==ADC_u32TIMEOUT)
		{
			/*loop is broken the time out is reached*/
			Local_u8ErrorState=STD_TYPES_NOK;
		}
		else
		{
			/* Loop is broken because flagis raised */

			/* Clear the conversion complete flag */
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADIF);

			/* Return the reading */
			*Copy_pu16Reading=ADC_u8_ADCH_REG;

			/* ADC is finished, return it to IDLE */
			ADC_u8BusyState= IDLE;
		}
	}
	else
	{
		Local_u8ErrorState= BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel,u16* Copy_pu16Reading,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(ADC_u8BusyState == IDLE)
	{

		if(Copy_pu16Reading == NULL || Copy_pvNotificationFunc == NULL)
		{
			Local_u8ErrorState=STD_TYPES_NOK;
		}
		else
		{
			/* Make ADC busy inorder not to work until being idle */
			ADC_u8BusyState= BUSY;

			/* Initialize the reading variable globally */
			ADC_pu16Reading=Copy_pu16Reading;

			/* Initialize the callback notification function globally */
			ADC_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

			/* Clear the Mux bits in the ADMUX register */
			ADC_u8_ADMUX_REG &= 0b11100000;

			/* Set the required channel into the MUX bits */
			ADC_u8_ADMUX_REG |= Copy_u8Channel;

			/* Start conversion */
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADSC);

			/* ADC interrupt enable */
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADIE);

		}

	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/* read ADC result */
	*ADC_pu16Reading= ADC_u8_ADCH_REG;

	/* make ADC state be idle because it finished */
	ADC_u8BusyState= IDLE;

	/* Invoke the call back notification function */
	ADC_pvCallBackNotificationFunc();

	/* Disable ADC conversion complete interrupt */
	CLR_BIT(ADC_u8_ADCSRA_REG,ADC_ADCSRA_ADIE);
}
