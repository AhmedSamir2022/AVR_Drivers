/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:RTOS STACK   ************************/
/*********************    COMPONENT:TIMER0   ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER0_voidInit(void);

u8 TIMER0_u8CompMatchSetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
