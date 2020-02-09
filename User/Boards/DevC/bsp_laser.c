/* Includes ------------------------------------------------------------------*/
#include "bsp_laser.h"
#include "tim.h"

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function  ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
int BSP_Laser_Start(void) {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	return 0;
}

int BSP_Laser_Set(float duty_cycle) {
	if (duty_cycle > 1.f)
		return -1;
	
	uint16_t pulse = duty_cycle * UINT16_MAX;

	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pulse);

	return 0;
}

int BSP_Laser_Stop(void) {
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
	return 0;
}