/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for ADC driver
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#ifndef ADC_FILES
#define ADC_FILES
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADC_INTERRUPT_ENABLE_BIT 3
#define ADC_MODULE_ENABLE_BIT 7
#define START_CONVERSION_ENABLE_BIT 6
#define ADC_INTERRUPT_FLAG_BIT 4
#include "std_types.h"
typedef enum {
	AREF_MODE,AVCC_MODE,RESERVED,INTERNAL_MODE
}Reference_Selection_BIT;
typedef enum
{
	NO_PRESCALER,PRESCALER_2,PRESCALER_4,PRESCALER_8,PRESCALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128
}ADC_PRESCALER;
typedef struct
{
	Reference_Selection_BIT reference_mode;
	ADC_PRESCALER prescaler;
}ADC_ConfigType;
void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channel_number);
#endif
