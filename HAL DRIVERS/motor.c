/*
 * motor.c
 *
 *  Created on: Oct 7, 2022
 *      Author: HSNUS
 */
#include "motor.h"
#include "timer_pwm.h" // Can be operated using PWM or SPI that's why I included this in .c file
void DcMotor_Init(void){
	GPIO_setupPinDirection( MOTOR_FIRST_PORT_ID , MOTOR_FIRST_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection( MOTOR_SECOND_PORT_ID , MOTOR_SECOND_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(MOTOR_FIRST_PORT_ID, MOTOR_FIRST_PIN_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_SECOND_PORT_ID, MOTOR_SECOND_PIN_ID,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	if(state==STOP)
	{
		GPIO_writePin(MOTOR_FIRST_PORT_ID, MOTOR_FIRST_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_SECOND_PORT_ID, MOTOR_SECOND_PIN_ID,LOGIC_LOW);
	}
	else if(state==A_CW){
		GPIO_writePin(MOTOR_FIRST_PORT_ID, MOTOR_FIRST_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_SECOND_PORT_ID, MOTOR_SECOND_PIN_ID,LOGIC_HIGH);
	}
	else if(state==CW){
		GPIO_writePin(MOTOR_FIRST_PORT_ID, MOTOR_FIRST_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_SECOND_PORT_ID, MOTOR_SECOND_PIN_ID,LOGIC_LOW);

	}
	PWM_Timer0_Init(speed);
}
