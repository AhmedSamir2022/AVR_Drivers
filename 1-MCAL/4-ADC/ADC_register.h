/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:ADC      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define ADC_u8_ADMUX_REG        *((volatile u8*)0x27)         //ADC multiplexer selection register

#define ADC_ADMUX_REF1       7                             //Reference selection bit1
#define ADC_ADMUX_REF0       6                             //Refernce selection bit0
#define ADC_ADMUX_ADLR       5                             //ADC left adjust result

#define ADC_u8_ADCSRA_REG       *((volatile u8*)0x26)         //ADC control and status register A

#define ADC_ADCSRA_ADEN      7                             //ADC enable
#define ADC_ADCSRA_ADSC      6                             //Start conversion
#define ADC_ADCSRA_ADATE     5                             //Auto trigger enanle
#define ADC_ADCSRA_ADIF      4                             //Interrupt flag
#define ADC_ADCSRA_ADIE      3                             //Interruptt enable
#define ADC_ADCSRA_ADPS2     2                             //Prescaler bit2
#define ADC_ADCSRA_ADPS1     1                             //Prescaler bit1
#define ADC_ADCSRA_ADPS0     0                             //Prescaler bit0

#define ADC_u8_ADCH_REG         *((volatile u8*)0x25)         //ADC high register

#define ADC_u8_ADCL_REG         *((volatile u8*)0x24)         //ADC low register

#define ADC_u16_ADC_REG                  *((volatile u16*)0x24)

#endif
