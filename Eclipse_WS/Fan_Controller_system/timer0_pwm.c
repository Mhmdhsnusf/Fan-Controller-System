/******************************************************************************
 *
 * Module: Timer0 PWM Mode
 *
 * File Name: timer0_pwm.c
 *
 * Description: source file for the timer0 PWM mode driver
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#include<avr/io.h>
#include "common_macros.h"
#include "gpio.h"
#include "timer0_pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for initializing Timer0 in PWM mode
 */
void PWM_Timer0_Init(uint8 duty_cycle_percent)
{

	TCNT0 = 0;
	OCR0  = ((255*duty_cycle_percent)/100); // Set Compare Value
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);//set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/*Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}



