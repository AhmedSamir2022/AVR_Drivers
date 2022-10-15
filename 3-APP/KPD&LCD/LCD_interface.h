/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/ 
/*********************    LAYER:HAL          ************************/ 
/*********************    COMPONENT:CLCD     ************************/ 
/*********************    VERSION:1.00       ************************/ 
/*********************    DATE:26/9/2021     ************************/
/********************************************************************/  

/* Preprocessor File Guard */
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

enum LCD_enumDirections{
       LEFT, RIGHT, UP, DOWN, NONE
}option;

void LCD_VoidSendCommand(u8 Copy_u8Command);
void LCD_VoidSendData(u8 Copy_u8Data);
void LCD_VoidInit(void);
void LCD_ViodSendString(const char* Copy_pcString);
void LCD_VoidGoToXY(u8 Copy_u8XPOs,u8 Copy_u8YPos);
void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
void LCD_voidClear(void);
void LCD_voidWriteNumber(u32 number);
void LCD_voidShiftDisplay(enum LCD_enumDirections enumDirection);

#endif
