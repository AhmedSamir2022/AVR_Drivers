/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:ADC      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16Reading);
u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel,u16* Copy_pu16Reading,void(*Copy_pvNotificationFunc)(void));


#endif
