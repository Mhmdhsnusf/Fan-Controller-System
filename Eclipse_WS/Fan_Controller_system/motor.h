/*
 * motor.h
 *
 *  Created on: Oct 7, 2022
 *      Author: HSNUS
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
#include "gpio.h"
#define MOTOR_FIRST_PORT_ID PORTB_ID
#define MOTOR_FIRST_PIN_ID PIN0_ID
#define MOTOR_SECOND_PORT_ID PORTB_ID
#define MOTOR_SECOND_PIN_ID PIN1_ID
typedef enum {
	STOP,CW,A_CW
}DcMotor_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_H_ */
