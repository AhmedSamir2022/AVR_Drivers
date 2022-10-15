/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:HAL          ************************/
/*********************    COMPONENT:CLCD     ************************/
/*********************    VERSION:1.00       ************************/
/*********************    DATE:26/9/2021     ************************/
/********************************************************************/

/* Lib Layer */
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include  <avr/delay.h>
/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_VoidSendCommand(u8 Copy_u8Command)
{
	/* 1- Rs = 0 Select Data Register */
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* 2- Rw = 0 Write Operation */
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* 3- Send Data Byte to LCD  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Command);
	/* 4- Send Enable Pulse */
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
}
void LCD_VoidSendData(u8 Copy_u8Data)
{
	/* 1- Rs = 1 Select Data Register */
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* 2- Rw = 0 Write Operation */
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* 3- Send Data Byte to LCD  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);
	/* 4- Send Enable Pulse */
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
}
void LCD_VoidInit(void)
{
	_delay_ms(40);

	/* Send Functoin Set Command */
	LCD_VoidSendCommand(0b00111000);

	/* Send Display on off Control Command */
	LCD_VoidSendCommand(0b00001100);

	/* Send Display Clear Command */
	LCD_VoidSendCommand(1);

    /* Send Entry Mode Set Command */
    LCD_VoidSendCommand(0b00000110);
}
void LCD_ViodSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		LCD_VoidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
void LCD_VoidGoToXY(u8 Copy_u8XPOs,u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	// Location is at first line
	if(Copy_u8XPOs==0)
	{
		Local_u8Address=Copy_u8YPos;
	}
	// Location is at second line
	else if(Copy_u8XPOs==1)
	{
		Local_u8Address=Copy_u8YPos+0x40;
	}
	//set bit number 7 for set DDRAM Address Command then send the command
	LCD_VoidSendCommand(Local_u8Address+128);
}
void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0,Local_u8Iterator;
	/* calculate CGRAM address */
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	/* send CGRAM address command to lcd with setting bit 6 and clearing bit 7 */
	LCD_VoidSendCommand(Local_u8CGRAMAddress+64);
	/* write pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_VoidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/* go back to DDRAM to display the pattern */
	LCD_VoidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/* Display the pattern written in the CGRAM */
	LCD_VoidSendData(Copy_u8PatternNumber);
}
void LCD_voidClear(void)
{
        //display clear
	LCD_VoidSendCommand(0b00000001);
        _delay_ms(2);
}
void LCD_voidShiftDisplay(enum LCD_enumDirections enumDirection)
{
        switch (enumDirection) {
        case LEFT:
                LCD_VoidSendCommand(0b00011000);
                break;

        case RIGHT:
        	    LCD_VoidSendCommand(0b00011100);
                break;

        default:
                //empty
                break;
        }
}


