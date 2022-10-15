/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:EEPROM      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#ifndef EEP_REGISTER_H
#define EEP_REGISTER_H

#define EEP_u8_EEARL_REG        *((volatile u8*)0x3E)
#define EEP_u8_EEARH_REG        *((volatile u8*)0x3F)

#define EEP_u8_EEDR_REG         *((volatile u8*)0x3D)

#define EEP_u8_EECR_REG         *((volatile u8*)0x3C)
#define EEP_EECR_EERE           0
#define EEP_EECR_EEWE           1
#define EEP_EECR_EEMWE          2
#define EEP_EECR_EERIE          3

#define  SPMCR                  *((volatile u8*)0x57)
#define  SPMCR_SPMEN            0

#endif
