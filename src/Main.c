/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
//#include "system_stm32f4xx.h"
#include "AssemblyModule.h"
#include "Led.h"
#include "UserLed.h"

#define SystemCoreClock  400000

void initSysTick();

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s

uint32_t variableInC = 0xdeaf;

void wait(void) {
	volatile int counter = 500000;
	while(counter--);
}

int main() {
	fourBytes = 0xdeadbeef;
	noArgFunc();

	initLED(LED3);
	initLED(LED4);

	initSysTick();

	while(1) {
		turnOnLED(LED3);
//		GPIOG->ODR &= LED3;
		wait();
		turnOffLED(LED3);
//		GPIOG->ODR &= ~LED3;
		wait();
	}

	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;
}

/*
void SystemInit()	{
	// Do nothing at the moment because we are
	// not going to deal with any hardware
}
*/

void initSysTick() {
  /* Setup SysTick Timer for 1 msec interrupts.
     ------------------------------------------
    1. The SysTick_Config() function is a CMSIS function which configure:
       - The SysTick Reload register with value passed as function parameter.
       - Configure the SysTick IRQ priority to the lowest value (0x0F).
       - Reset the SysTick Counter register.
       - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
       - Enable the SysTick Interrupt.
       - Start the SysTick Counter.

    2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
       SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
       SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
       inside the misc.c file.

    3. You can change the SysTick IRQ priority by calling the
       NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function
       call. The NVIC_SetPriority() is defined inside the core_cm4.h file.

    4. To adjust the SysTick time base, use the following formula:

         Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)

       - Reload Value is the parameter to be passed for SysTick_Config() function
       - Reload Value should not exceed 0xFFFFFF
   */
  if (SysTick_Config(SystemCoreClock / 1000))
  {
    /* Capture error */
    while (1);
  }
}
