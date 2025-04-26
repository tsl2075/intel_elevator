

#include "servo.h"


DoorState doorState = DOOR_IDLE;


void Door_Update()
{
    uint32_t now = HAL_GetTick();
    uint32_t doorTimer = 0;  // 시간 체크용

    switch (doorState)
    {
        case DOOR_OPENING:
	  DOOR_Open();
	  doorTimer = now;
	  doorState = DOOR_OPEN_WAIT;
	  break;

        case DOOR_OPEN_WAIT:
          // 주기적으로 초음파 트리거
           static uint32_t lastTrigger = 0;
           if (now - lastTrigger >= 250)
           {
               HCSR04_Trigger();
               printf(" %d cm\r\n", GetDistance());
               lastTrigger = now;
           }

           // 초음파 결과 기반 판단
           if (GetDistance() < 16)  // 사람이 앞에 있으면
           {
               doorTimer = now;  // 닫힘 타이머 리셋 (지연)
               printf("person detection, close wait\n");
           }//Buzzer_Alert(3, 100);  // 삐삐삐 경고

            if (now - doorTimer >= 2000)  // 2초 지난 후
            {
                doorState = DOOR_CLOSING;
            }
            break;

        case DOOR_CLOSING:
            DOOR_Close();  // 서보모터 닫기
            doorState = DOOR_IDLE;
            break;

        default:
            break;
    }
}

void Door_RequestOpen()
{
    if (doorState == DOOR_IDLE)
      {
        doorState = DOOR_OPENING;
      }
}



void DOOR_Open()
{
  TIM1->CCR2 = 21; // 90도 - 문 열기
}

void DOOR_Close()
{
  TIM1->CCR2 = 68; // 0도 - 문 닫기
}






















