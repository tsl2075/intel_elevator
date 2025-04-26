
#include "ultrasonic.h"


uint16_t IC_Value1 = 0;	// 에코핀이 하이엣지일때
uint16_t IC_Value2 = 0;	// 에코핀이 로우엣지일때
uint16_t echoTime = 0;	// 에코핀의 하이엣지와 로우엣지 사이의 시간(카운트갯수)
uint8_t captureFlag = 0;	// 엣지됬음을 확인
uint8_t distance =0;	// 거리
// static을 걸면 다른 C,H에서 접근을 하지 못한다.


void HCSR04_Trigger(void)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);
    delay_us(1);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);	// 데이터시트 참고
    delay_us(10);	// 펄스 내보내기 위해 10us동안 딜레이
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);

    __HAL_TIM_ENABLE_IT(&htim3, TIM_IT_CC1);	// 타이머의 인터럽트를 활성화 할껀데 누구를 ? -> 타이머3번의 타이머 인터럽트 채널 1번
}


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
  {
      if(captureFlag == 0)	// 아직 캡쳐 안했으면
	{
	  // 첫번째 밸류에 캡처인터럽트가 발생하면 카운트값을 가져옴
	  IC_Value1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
	  captureFlag=1;	// 캡처 했다고 플래그 세움

	  __HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);

	}
      else if(captureFlag == 1)	// 한번 캡쳐 했으면
	{
	  IC_Value2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
	  __HAL_TIM_SET_COUNTER(&htim3,0);

	  if(IC_Value2 > IC_Value1)
	    {
		echoTime = IC_Value2 - IC_Value1;
	    }
	  else if(IC_Value1 > IC_Value2)
	    {
	      echoTime = (0xFFFF - IC_Value1) + IC_Value2;
	    }
	    distance = echoTime / 58;	// 거리가 나옴 데이터시트 참고
	    //StoreDistance(distance);  //  평균 거리 버퍼에 저장

	    captureFlag = 0;
	    __HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
	    __HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
      }
  }
}


uint8_t GetDistance(void)
{
    return distance;
}













