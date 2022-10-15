/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/ 
/*********************    LAYER:HAL          ************************/ 
/*********************    COMPONENT:CLCD     ************************/ 
/*********************    VERSION:1.00       ************************/ 
/*********************    DATE:26/9/2021     ************************/
/********************************************************************/  

/*Preprocessor File Guard*/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Config For LCD PINS */

/*Data Pins*/
#define LCD_u8_DATA_PORT     DIO_u8_PORTD

/* RS Pin */
#define LCD_u8_RS_PORT       DIO_u8_PORTB
#define LCD_u8_RS_PIN        DIO_u8_PIN2

/* RW Pin */
#define LCD_u8_RW_PORT       DIO_u8_PORTB
#define LCD_u8_RW_PIN        DIO_u8_PIN1

/* Enable Pin */
#define LCD_u8_EN_PORT       DIO_u8_PORTB
#define LCD_u8_EN_PIN        DIO_u8_PIN0



#endif                         
