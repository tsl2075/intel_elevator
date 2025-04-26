
#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"
#include "ultrasonic.h"
#include <stdio.h>
#include "buzzer.h"

typedef enum
{
    DOOR_IDLE,
    DOOR_OPENING,
    DOOR_OPEN_WAIT,
    DOOR_CLOSING
} DoorState;

void Door_Update();		// 도어제어 함수
void Door_RequestOpen();	// 도어열기 요청 함수
void DOOR_Open();
void DOOR_Close();
extern DoorState doorState;  //  전역 변수 선언



#endif /* INC_SERVO_H_ */
