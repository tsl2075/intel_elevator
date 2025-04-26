
#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_


#include "main.h"
#include <stdlib.h>
#include "delay.h"
#include "led.h"
#include "button.h"
#include "servo.h"
#include "i2c_lcd.h"
#include "buzzer.h"


#define DIR_CW			0	// 시계 방향 - CW-클럭와이즈
#define DIR_CCM			1	// 반시계 방향
#define STEPS_PER_FLOOR 	6000

#define IN1_PIN		GPIO_PIN_12
#define IN1_GPIO_Port	GPIOB


#define IN2_PIN		GPIO_PIN_13
#define IN2_GPIO_Port	GPIOB
#define IN3_PIN		GPIO_PIN_14
#define IN3_GPIO_Port	GPIOB
#define IN4_PIN		GPIO_PIN_15
#define IN4_GPIO_Port	GPIOB

#define SENSOR1_Pin 		GPIO_PIN_0
#define SENSOR1_GPIO_Port 	GPIOC

#define SENSOR2_Pin 		GPIO_PIN_1
#define SENSOR2_GPIO_Port 	GPIOC

#define SENSOR3_Pin 		GPIO_PIN_2
#define SENSOR3_GPIO_Port 	GPIOC



static const uint8_t HALF_STEP_SEQ[8][4] =
    {
	{1, 0, 0, 0},
	{1, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 1, 0},
	{0, 0, 1, 0},
	{0, 0, 1, 1},
	{0, 0, 0, 1},
	{1, 0, 0, 1}
    };

void stepMotor(uint8_t step);
void rotateSteps(uint16_t steps, uint8_t direction);
void rotateDegrees(uint16_t degrees, uint8_t direction);
void stopMotor();
void moveElevator();

void test_steps();
void updateCur();


#endif /* INC_STEPPER_H_ */
