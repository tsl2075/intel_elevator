

#include "buzzer.h"


void Buzzer(uint32_t duration_ms)
{
    // 원하는 주파수로 설정 (예: 2kHz)
    TIM1->PSC = 383;
/*
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

    HAL_Delay(duration_ms);  // 울리는 시간

    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);  // 멈춤
*/
}


void Buzzer_Alert(uint8_t count, uint32_t duration_ms)
{
    for (int i = 0; i < count; i++)
    {
	Buzzer(duration_ms);
        HAL_Delay(100);  // 간격
    }
}
