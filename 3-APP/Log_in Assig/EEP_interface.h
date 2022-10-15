/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:EEPROM      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#ifndef EEP_INTERFACE_H
#define EEP_INTERFACE_H

void EEPROM_Init(void);
u8 EEPROM_write(u16 Copy_u16Address,u8 Copy_u8Data);
u8 EEPROM_read(u16 Copy_u16Address,u8* Copy_pu8Data);
void EEPROM_writeString(u16 EEPROM_StartAddress,u8* Password);
void EEPROM_readString(u16 Copy_u16StartAddress,u8* Copy_pu8Password);

#endif
