/*
 * main.c
 *
 *  Created on: Oct 7, 2022
 *      Author: HSNUS
 */
#include "adc.h"
#include "lcd.h"
#include "gpio.h"
#include "lm35_sensor.h"
#include "common_macros.h"
#include "motor.h"

int main(void){
	LCD_init();
	ADC_ConfigType currentConfig;
	currentConfig.prescaler=PRESCALER_8;
	currentConfig.reference_mode=INTERNAL_MODE;
	ADC_init(&currentConfig);
	DcMotor_Init();
	LCD_displayStringRowColumn(0,3,"FAN IS ");
	LCD_displayStringRowColumn(1,3,"TEMP =  ");
	uint8 currentTemperature=0;

	while(1){
		currentTemperature=LM35_getTemperature();
		if(currentTemperature<30){
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0,9," OFF");
			LCD_moveCursor(1,9);
			LCD_displayChar(' ');
			LCD_intgerToString(currentTemperature);

		}
		else if(currentTemperature>=30&&currentTemperature<60){
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,9," ON ");
			LCD_moveCursor(1,9);
			LCD_displayChar(' ');
			LCD_intgerToString(currentTemperature);
		}
		else if(currentTemperature>=60&&currentTemperature<90){
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,9," ON ");
			LCD_moveCursor(1,9);
			LCD_displayChar(' ');
			LCD_intgerToString(currentTemperature);
		}
		else if(currentTemperature>=90&&currentTemperature<120){
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,9," ON ");
			LCD_moveCursor(1,9);
			LCD_displayChar(' ');
			LCD_intgerToString(currentTemperature);
		}
		else if(currentTemperature>=120){
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,9," ON ");
			LCD_moveCursor(1,9);
			LCD_displayChar(' ');
			LCD_intgerToString(currentTemperature);
		}
		else{

		}
		LCD_displayString(" C");




	}

	return 0;
}


