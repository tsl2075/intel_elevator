
#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"
#include "ultrasonic.h"

#define Do	383	// 음계
#define Re	340
#define Mi	304
#define Fa	287
#define Sol	255
#define Ra	227
#define Si	203
#define Dol	191

#define qNote	600	// 음의 길이
#define wNote	1800


void Buzzer(uint32_t duration_ms);				// 부저 소리 1회 울리기
void Buzzer_Alert(uint8_t count, uint32_t duration_ms);		// 사람 감지시 경고음(여러번) 울리기


#endif /* INC_BUZZER_H_ */
