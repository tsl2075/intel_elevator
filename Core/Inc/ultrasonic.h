
#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_
#define AVG_WINDOW 5


#include "main.h"
#include "tim.h"
#include "delay.h"
#include <stdio.h>

#define TRIG_PORT 	GPIOB
#define TRIG_PIN 	GPIOB_PIN_8


void HCSR04_Trigger(void);


uint8_t GetDistance(void); // 거리확인 함수 servo에서 사용해서 문 동작시 멈추도록
uint8_t GetAveragedDistance();

#endif /* INC_ULTRASONIC_H_ */
