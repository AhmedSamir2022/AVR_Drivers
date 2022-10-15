/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:EEPROM      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EEP_interface.h"
#include "EEP_config.h"
#include "EEP_register.h"
#include "DIO_interface.h"
#define  F_CPU  8000000UL
#include <avr/delay.h>


void EEPROM_Init(void)
{
	DIO_u8SetPortValue(EEP_u8_EEARH_REG,DIO_u8_LOW);
	DIO_u8SetPortValue(EEP_u8_EEDR_REG,DIO_u8_LOW);
	DIO_u8SetPortValue(EEP_u8_EECR_REG,DIO_u8_LOW);
}

u8 EEPROM_write(u16 Copy_u16Address,u8 Copy_u8Data)
{
	if(Copy_u16Address > EEPROM_SIZE)
	{
		return EEPROM_INVALID_ADDRESS;
	}
	else
	{
		/* Wait for completion of previous write */
		while(GET_BIT(EEP_u8_EECR_REG,EEP_EECR_EEWE));
		while(SPMCR & (1<<SPMCR_SPMEN));
		/* Set up address and data registers */
		EEP_u8_EEARH_REG = Copy_u16Address>>8;
		EEP_u8_EEARL_REG = Copy_u16Address;
		EEP_u8_EEDR_REG= Copy_u8Data;

		/* Write logical one to EEMWE */
		//SET_BIT(EEP_u8_EECR_REG,EEP_EECR_EEMWE);
		asm("SBI 0x1C,2");
		/* Start eeprom write by setting EEWE */
		asm("SBI 0x1C,1");
		//SET_BIT(EEP_u8_EECR_REG,EEP_EECR_EEWE);
		_delay_ms(10);
		return EEPROM_OK;
	}

}

u8 EEPROM_read(u16 Copy_u16Address,u8* Copy_pu8Data)
{
	if(Copy_u16Address > EEPROM_SIZE)
	{
		return EEPROM_INVALID_ADDRESS;
	}
	else
	{
		/* Wait for completion of previous write */
		while(GET_BIT(EEP_u8_EECR_REG,EEP_EECR_EEWE));
		while(GET_BIT(SPMCR,SPMCR_SPMEN));
		/* Set up address register */
		EEP_u8_EEARH_REG = Copy_u16Address>>8;
		EEP_u8_EEARL_REG = Copy_u16Address;

		/* Start eeprom read by writing EERE */
		SET_BIT(EEP_u8_EECR_REG,EEP_EECR_EERE);

		/* Return data from data register */
		*Copy_pu8Data = EEP_u8_EEDR_REG;
		_delay_ms(10);
		return EEPROM_OK;
	}
}

void EEPROM_writeString(u16 Copy_u16StartAddress,u8* Copy_pArru8Password)
{
	while(*Copy_pArru8Password!='\0')
	{
		EEPROM_write(Copy_u16StartAddress++,*Copy_pArru8Password);
		Copy_pArru8Password++;
	}
	EEPROM_write(Copy_u16StartAddress,'\0');//to check the end of my string"password"
}

void EEPROM_readString(u16 Copy_u16StartAddress,u8* Copy_pArru8Password)
{
	do
	{
		EEPROM_read(Copy_u16StartAddress++,Copy_pArru8Password);

	}while(*Copy_pArru8Password != '\0' && Copy_pArru8Password++);
}






