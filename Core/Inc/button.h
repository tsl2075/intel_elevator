
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "gpio.h"
#include <stdbool.h>

typedef struct
{
  GPIO_TypeDef *port;
  uint16_t	pinNumber;
  GPIO_PinState	onState;
}BUTTON_CONTROL;

bool buttonGetPressed(uint8_t num); //트루아니면 펄스 무조건 반환
void checkButtons();

#endif /* INC_BUTTON_H_ */
