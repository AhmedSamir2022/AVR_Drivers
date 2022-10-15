/********************************************************************/
 /*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:RTOS STACK   ************************/
/*********************    COMPONENT:TIMER0   ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TImer0_pvCompMatchCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/* Initialize waveform generation mode to work as CTC mode */
	SET_BIT(TIMER_TCCR0_REG,TIMER_TCCRO_WGM00);
	SET_BIT(TIMER_TCCR0_REG,TIMER_TCCRO_WGM01);

	/* Set the required compare match value */
	/*TIMER_OCR_REG = TIMER0_u8COMP_MATCH_VAL;*/

	/* Timer0 compare match interrupt enable */
	/*SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0);*/

	/* clear on comp match value, set on top */
	CLR_BIT(TIMER_TCCR0_REG,TIMER_TCCRO_COM00);
	SET_BIT(TIMER_TCCR0_REG,TIMER_TCCRO_COM01);
	
	/* Set the required prescaler */

	TIMER_TCCR0_REG &= TIMER0_PRESCALER_MASK;
	TIMER_TCCR0_REG |= TIMER0_u8PRESCALER;
	
}

u8 TIMER0_u8CompMatchSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TImer0_pvCompMatchCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
	
}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	TIMER_OCR_REG=Copy_u8Value;
}

/* Timer0 compare match ISR */
void __vector_11 (void)	__attribute__((signal));
void __vector_11 (void)
{
	if(TImer0_pvCompMatchCallBackFunc != NULL)
	{
		TImer0_pvCompMatchCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}
