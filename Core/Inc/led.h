
#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"
#include <stdio.h>

typedef enum
{
    DIR_STOP = 0,
    DIR_UP,
    DIR_DOWN
} Direction;


#define LATCH_PIN GPIO_PIN_1  // PB1
#define CLOCK_PIN GPIO_PIN_2  // PB2
#define DATA_PIN  GPIO_PIN_0  // PB0

#define LATCH_PORT GPIOB
#define CLOCK_PORT GPIOB
#define DATA_PORT  GPIOB

#define LED_SPEED 70  // 원하는 값으로 조절 가능 숫자 줄이면 빨라짐

// 핀 상태 변경 매크로
#define LATCH_HIGH() HAL_GPIO_WritePin(LATCH_PORT, LATCH_PIN, GPIO_PIN_SET)
#define LATCH_LOW()  HAL_GPIO_WritePin(LATCH_PORT, LATCH_PIN, GPIO_PIN_RESET)
#define CLOCK_HIGH() HAL_GPIO_WritePin(CLOCK_PORT, CLOCK_PIN, GPIO_PIN_SET)
#define CLOCK_LOW()  HAL_GPIO_WritePin(CLOCK_PORT, CLOCK_PIN, GPIO_PIN_RESET)
#define DATA_HIGH()  HAL_GPIO_WritePin(DATA_PORT, DATA_PIN, GPIO_PIN_SET)
#define DATA_LOW()   HAL_GPIO_WritePin(DATA_PORT, DATA_PIN, GPIO_PIN_RESET)

#define LED_PATTERN_UP_START   0x80000000000000
#define LED_PATTERN_DOWN_START 0x00000000000001
#define LED_PATTERN_FULL       0xFFFFFFFFFFFFFF

extern uint64_t pattern_up;
extern uint64_t pattern_down;

void shift_Out(uint64_t data);
void LED_Update(Direction dir);



#endif /* INC_LED_H_ */
