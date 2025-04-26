
#include "stepper.h"
#include <stdio.h>

extern volatile uint8_t cur;
extern volatile uint8_t tar;
extern Direction moveDir;


void moveElevator()
{
    if (cur == tar) return;

    uint8_t direction;
    uint16_t steps = STEPS_PER_FLOOR * abs(tar - cur);

    if (tar > cur)
      {
	direction = DIR_CCM; // 올라감
	moveDir = DIR_UP;       //  LED용 방향 설정
      }
    else
      {
	direction = DIR_CW;  // 내려감
	moveDir = DIR_DOWN;
      }
    rotateSteps(steps, direction);
    stopMotor();
}

// 폴링방식으로도 멈추도록 설정함
// 혹시나 포토인터럽트가 너무 빨라서 인식을 못 할 경우 생각해서
void updateCur()
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET)
      {
      cur = 1;
      }

    else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == GPIO_PIN_SET)
      {
        cur = 2;
      }

    else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) == GPIO_PIN_SET)
      {
        cur = 3;
      }
}

void stopMotor()
{
    // 모든 스텝 모터 핀을 LOW 상태로 설정하여 모터를 멈추게 합니다.
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_PIN, GPIO_PIN_RESET);
}


void stepMotor(uint8_t step)
{
  HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_PIN, HALF_STEP_SEQ[step][0]);
  HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_PIN, HALF_STEP_SEQ[step][1]);
  HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_PIN, HALF_STEP_SEQ[step][2]);
  HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_PIN, HALF_STEP_SEQ[step][3]);
}// 0을 보내면 스텝의{1,0,0,0} 에서 1을 준다는 뜻

void rotateSteps(uint16_t steps, uint8_t direction)
{
    char line2[17];
    static uint8_t currentStep = 0;
    printf("rotateSteps: %d steps, dir=%s\n", steps, direction == DIR_CCM ? "UP" : "DOWN");

    for(uint16_t i = 0; i < steps; i++)
    {
	updateCur(); //  먼저 위치 확인!

	if (cur == tar)
	{
	    stopMotor();
	    moveDir = DIR_STOP;
	    //  LED 즉시 꺼짐 + 패턴 초기화
	    shift_Out(0);
	    pattern_up = LED_PATTERN_UP_START;
	    pattern_down = LED_PATTERN_DOWN_START;
	    Door_RequestOpen();
	    break;
	}

	LED_Update(moveDir);  //  도착 이후에만 동작
        stepMotor(currentStep);

        if (direction == DIR_CW)
          {
            sprintf(line2, "GOING DOWN");
            currentStep = (currentStep + 1) % 8;
          }
        else
          {
            sprintf(line2, "GOING UP ");
            currentStep = (currentStep + 7) % 8;
          }

        if (i % 100 == 0)
          {
            LCD_UPDOWN(cur, tar, line2);
            LED_Update(moveDir); // 회전 중 애니메이션 진행
            printf("  progress: %d\n", i);
          }

        delay_us(2000); // 3층 포토인터럽트 동작이 잘 안되서 시간을 늘림
    }
    stopMotor(); // 중단이든 완료든 항상 멈추기
    printf("Finished rotateSteps\n");
    //Buzzer(100);  // 도착 알림
}









