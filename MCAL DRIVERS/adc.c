/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: source file for ADC driver
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#include<avr/io.h>
#include "common_macros.h"
#include "lcd.h"
#include "adc.h"
void ADC_init(const ADC_ConfigType * config_Ptr){
	ADMUX = (ADMUX&0x3F)|((config_Ptr->reference_mode)<<6); // Working with AVCC
	ADMUX &= 0xE0; // Clearing the first five bits in ADMUX
	ADCSRA = (ADCSRA & 0xF8)|(config_Ptr->prescaler & 0x07); //CLOCK 128
	CLEAR_BIT(ADCSRA,ADC_INTERRUPT_ENABLE_BIT); //Disable interrupt
	SET_BIT(ADCSRA, ADC_MODULE_ENABLE_BIT); //Enable ADC
}
uint16 ADC_readChannel(uint8 channel_number){
	ADMUX = (ADMUX&0xE0)|(channel_number&0x07); //Choose pin
	SET_BIT(ADCSRA,START_CONVERSION_ENABLE_BIT); //Start conversion
	while(BIT_IS_CLEAR(ADCSRA,ADC_INTERRUPT_FLAG_BIT)); // Polling check flag
	SET_BIT(ADCSRA,ADC_INTERRUPT_FLAG_BIT); // Clear flag
	return ADC;
}


