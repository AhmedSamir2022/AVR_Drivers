/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:ADC      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);

u8 ADC_u8GetDigitalValue(u8 Copy_u8ChannelNum,u16* Copy_pu16ReturnedDigitalValue);

#endif
