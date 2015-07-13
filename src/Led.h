#ifndef __Led_H__
#define	__Led_H__

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define _GPIO(x)		GPIO(x)
#define GPIO(x)			GPIO ## x

#define turnOnLED(x)  HAL_GPIO_WritePin(_GPIO(x ## _PORT), x, GPIO_PIN_SET);
#define turnOffLED(x) HAL_GPIO_WritePin(_GPIO(x ## _PORT), x, GPIO_PIN_RESET);

#define _enableGPIO(x)	enableGPIO(x)
#define enableGPIO(x)	__GPIO ## x ## _CLK_ENABLE()

#define initLED(x)	do {									\
						_enableGPIO(x ## _PORT);			\
						configureLED(_GPIO(x ## _PORT), x);	\
					} while(0)

void configureLED(GPIO_TypeDef *GPIO, uint32_t pin);

#endif	// __Led_H__
