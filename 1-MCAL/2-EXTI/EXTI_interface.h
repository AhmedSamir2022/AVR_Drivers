/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:EXTI     ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* EXTI Numbers Macros */
typedef enum{
	EXTI_u8_EXTI0=0,
	EXTI_u8_EXTI1,
	EXTI_u8_EXTI2
}EXTINum_t;

typedef enum{
	EXTI_u8_FALLING_EDGE=0,
	EXTI_u8_RAISING_EDGE,
	EXTI_u8_ANY_LOGICAL_CHANGE,
	EXTI_u8_LOW_LEVEL
}EXTITrigSrc_t;
u8 EXTI_u8EXTIInit   (EXTINum_t Copy_EnuEXTINum,EXTITrigSrc_t Copy_EnuEXTITriggerSrc);

u8 EXTI_u8EXTIEnable (EXTINum_t Copy_EnuEXTINum);

u8 EXTI_u8EXTIDisable(EXTINum_t Copy_EnuEXTINum);

u8 EXTI_u8SetCallBack(EXTINum_t Copy_EnuEXTINum, void(*Copy_pf)(void));

#endif
