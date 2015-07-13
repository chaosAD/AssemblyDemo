#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "Led.h"

void configureLED(GPIO_TypeDef *GPIO, uint32_t pin) {
	GPIO_InitTypeDef GpioInfo;

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = pin;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
//	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	// Init PG13 for LED
	HAL_GPIO_Init(GPIO, &GpioInfo);
}
