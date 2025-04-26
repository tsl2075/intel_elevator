
#include "button.h"

extern uint8_t tar;          // 목표층

void checkButtons()
{
    if (buttonGetPressed(0)) tar = 1;
    if (buttonGetPressed(1)) tar = 2;
    if (buttonGetPressed(2)) tar = 3;
}


BUTTON_CONTROL button[3]=
{
    {GPIOC, GPIO_PIN_10, 0}, //0은 눌렀을때의 상태 onState - 풀업저항방식
    {GPIOC, GPIO_PIN_11, 0},
    {GPIOC, GPIO_PIN_12, 0}
};




bool buttonGetPressed(uint8_t num)
{
  static uint32_t prevTime[3] = {0xFFFFFFFF, 0xFFFFFFFF ,0xFFFFFFFF}; //초기값을 큰 값으로 설정

  if(prevTime[num] == 0xFFFFFFFF) //첫 호출시 HAL_GetTick()으로 초기화
    {
      prevTime[num] = HAL_GetTick(); // 밀리초단위로 반환하는 HAL함수
    } //두번째 호출 될 때는 스킵됨

  bool ret = false;

  if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState) //만약 눌렀을때
    {
     uint32_t currTime = HAL_GetTick();

       if(currTime - prevTime[num] > 50) // 0.05초 이상 유지되는 경우에만 버튼 입력을 인정한다
	{
	  if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
	    {
	      ret = true; // 버튼이 실제로 눌려 있음을 확인
	    }
	  prevTime[num] = currTime; // 이전 시간을 갱신
	}
    }
  return ret; // 버튼이 50ms 이상 눌려 있는 경우 트루를 반환해서 눌린 상태임을 알리고
}









