
#include "led.h"


uint64_t pattern_up = LED_PATTERN_UP_START;
uint64_t pattern_down = LED_PATTERN_DOWN_START;
uint32_t lastUpdate = 0;	// non블로킹 방식



void LED_Update(Direction dir)
{
  if(dir == DIR_STOP)
  {
      shift_Out(0);  // OFF
      //  패턴도 초기화
      pattern_up = LED_PATTERN_UP_START;
      pattern_down = LED_PATTERN_DOWN_START;
      return;
  }

  uint32_t now = HAL_GetTick();

  if(now - lastUpdate < LED_SPEED) return;  // 100ms 주기 // LED 속도조절

  lastUpdate = now;

    if(dir == DIR_UP)
    {
        shift_Out(pattern_up);
        pattern_up |= pattern_up >> 1;  // 누적 점등

        if(pattern_up == LED_PATTERN_FULL)
          {
            pattern_up = LED_PATTERN_UP_START;
          }
    }
    else if(dir == DIR_DOWN)
    {
        shift_Out(pattern_down);
        pattern_down |= pattern_down << 1;  // 누적 점등 오른쪽

        if(pattern_down == LED_PATTERN_FULL)
          {
            pattern_down = LED_PATTERN_DOWN_START;
          }
    }

}


void shift_Out(uint64_t data)
{
	LATCH_LOW();  //  래치 신호 LOW (출력 고정)

    for (int i = 55; i >= 0; i--)
      {  // 16비트 데이터 전송
        if (data & (1ULL << i))
          //ULL = unsigned long long 의 접미사로 사용해야 64비트가 연산됨
          {
            DATA_HIGH();  // 1이면 HIGH
          }
        else
          {
            DATA_LOW();   // 0이면 LOW
          }
        CLOCK_HIGH();  //  클럭 HIGH (데이터 밀어넣기)
       	CLOCK_LOW();   //  클럭 LOW
    }
    LATCH_HIGH(); //  래치 신호 HIGH (출력 갱신)
}

















