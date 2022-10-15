/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:TIMER    ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H

#define TIMER_TCCR0_REG         *((volatile u8*)0x53) //Timer0 control register
#define TIMER_TCCRO_WGM00       6                     //waveform generation mode bit0   
#define TIMER_TCCRO_WGM01       3                     //waveform generation mode bit0
#define TIMER_TCCRO_CS02        2                     //Prescaler bit2
#define TIMER_TCCRO_CS01        1                     //Prescaler bit1
#define TIMER_TCCRO_CS00        0                     //Prescaler bit0 
#define TIMER_TCCRO_COM00       4                     //Prescaler bit0
#define TIMER_TCCRO_COM01       5                     //Prescaler bit0

#define TIMER_OCR_REG           *((volatile u8*)0x5C) //Output compare register 0

#define TIMER_TIMSK_REG         *((volatile u8*)0x59) //Timer mask 
#define TIMER_TIMSK_OCIE0       1                     //Output compare 0 interrupt enable  

#endif
