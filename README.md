## <img width="40" height="40" alt="Image" src="https://github.com/user-attachments/assets/26974821-a193-4930-8696-9775be0aad69" /> 프로젝트 개요
엘리베이터를 실제로 구현하면서 다양한 모듈들을 활용하기 위해 만든 프로젝트입니다.

## 개발 개요
- 프로젝트 : Elevator
- 개발기간 : 2025.03.21 ~ 03.27
- 개발 언어 : C


## <img width="40" height="40" alt="Image" src="https://github.com/user-attachments/assets/b37ebdf0-b93d-4a64-8740-0d5b58d975f7" /> 목표
- 서보모터와 스텝모터의 CCR,ARR값으로 주파수를 설정하고 PWM을 활용
- 실제로 레지스터가 부족하다고 가정을 하고 74HC595모듈인 8비트 시프트레지스터를 활용해서 최소의 핀을   활용해서 LED구현

## 주요 기술
- non-blocking

## <img width="40" height="40" alt="Image" src="https://github.com/user-attachments/assets/d2cb68cc-4a4d-4a2b-8ab9-24a5550d5e3f" /> Board
- STM32F411RE

## 세부설명
스텝모터와 서보모터 그리고 포토 인터럽트를 사용해 엘리베이터를 구현하고, 초음파센서를 활용해 물체 감지 및 시각적인 표현을 위해 LCD와 LED로 구현했습니다.
스텝모터와 서보모터의 CCR값을 통해 듀티비를 조절하고 ARR을 같이 활용해서 적당한 PWM을 조절함
ServoMotor을 사용할 때 Hal_GetTick을 활용하여 non-blocking 기법을 구현해서 사용


### Youtube 링크
https://www.youtube.com/shorts/yW5ClXnDxGI

### &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;동작영상   &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 
![eleva 동작 - Clipchamp로 제작](https://github.com/user-attachments/assets/c26ee2d6-dc65-41c3-9b82-ce773c2686b6)


### &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;물체감지영상   &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
![엘베 초음파 - Clipchamp로 제작](https://github.com/user-attachments/assets/a90e8c0a-82a5-46f7-bf9c-13cebc2be8ed) ![초음파 - Clipchamp로 제작](https://github.com/user-attachments/assets/819da5c2-4061-4f5b-9e3c-2c4e556da133)



