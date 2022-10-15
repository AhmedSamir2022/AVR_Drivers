/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:EXTI     ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void(*EXTI_Apf[3])(void)={NULL,NULL,NULL};

u8 EXTI_u8EXTIInit(EXTINum_t Copy_EnuEXTINum,
		EXTITrigSrc_t Copy_EnuEXTITriggerSrc) {
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Select EXTI Number */
	switch (Copy_EnuEXTINum) {
	case EXTI_u8_EXTI0:
		/* Select Trigger Source */
		switch (Copy_EnuEXTITriggerSrc) {
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC00);
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC01);
			/* Enable EXTI0 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT0);
			break;
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC00);
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC01);
			/* Enable EXTI0 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT0);
			break;
		case EXTI_u8_RAISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC00);
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC01);
			/* Enable EXTI0 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT0);
			break;
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC00);
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC01);
			/* Enable EXTI0 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT0);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		break;
	case EXTI_u8_EXTI1:
		/* Select Trigger Source */
		switch (Copy_EnuEXTITriggerSrc) {
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC10);
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC11);
			/* Enable EXTI1 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT1);
			break;
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC10);
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC11);
			/* Enable EXTI1 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT1);
			break;
		case EXTI_u8_RAISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC10);
			SET_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC11);
			/* Enable EXTI1 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT1);
			break;
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC10);
			CLR_BIT(EXTI_u8_MCUCR_REG, MCUCR_ISC11);
			/* Enable EXTI1 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT1);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		break;
	case EXTI_u8_EXTI2:
		/* Select Trigger Source */
		switch (Copy_EnuEXTITriggerSrc) {
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCSR_REG, MCUCSR_ISC2);
			/* Enable EXTI2 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT2);
			break;
		case EXTI_u8_RAISING_EDGE:
			SET_BIT(EXTI_u8_MCUCSR_REG, MCUCSR_ISC2);
			/* Enable EXTI2 */
			SET_BIT(EXTI_u8_GICR_REG, GICR_INT2);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		break;
	default:
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8EXTIEnable(EXTINum_t Copy_EnuEXTINum){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_EnuEXTINum){
	case EXTI_u8_EXTI0:SET_BIT(EXTI_u8_GICR_REG,GICR_INT0);break;
	case EXTI_u8_EXTI1:SET_BIT(EXTI_u8_GICR_REG,GICR_INT1);break;
	case EXTI_u8_EXTI2:SET_BIT(EXTI_u8_GICR_REG,GICR_INT2);break;
	default           :Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8EXTIDisable(EXTINum_t Copy_EnuEXTINum){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_EnuEXTINum){
	case EXTI_u8_EXTI0:CLR_BIT(EXTI_u8_GICR_REG,GICR_INT0);break;
	case EXTI_u8_EXTI1:CLR_BIT(EXTI_u8_GICR_REG,GICR_INT1);break;
	case EXTI_u8_EXTI2:CLR_BIT(EXTI_u8_GICR_REG,GICR_INT2);break;
	default           :Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8SetCallBack(EXTINum_t Copy_EnuEXTINum, void(*Copy_pf)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_EnuEXTINum >= EXTI_u8_EXTI0) && (Copy_EnuEXTINum <= EXTI_u8_EXTI2) && (Copy_pf != NULL)){
		/* Update Global Pointer to function */
		EXTI_Apf[Copy_EnuEXTINum] = Copy_pf;
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
/* ISR of EXTI0 Imp. */
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXTI_Apf[EXTI_u8_EXTI0] != NULL){
		EXTI_Apf[EXTI_u8_EXTI0]();
	}
}
/* ISR of EXTI1 Imp. */
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXTI_Apf[EXTI_u8_EXTI1] != NULL){
		EXTI_Apf[EXTI_u8_EXTI1]();
	}
}
/* ISR of EXTI2 Imp. */
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(EXTI_Apf[EXTI_u8_EXTI2] != NULL){
		EXTI_Apf[EXTI_u8_EXTI2]();
	}
}
