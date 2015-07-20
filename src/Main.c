/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"

// The following line is needed because the startup assembly
// code does not initialize SystemCoreClock variable. Please
// remove it once the initialization code is included.
#define SystemCoreClock  400000

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s

uint32_t variableInC = 0xdeaf;

void waitForever(void) {
	volatile int counter = 500000;
	while(counter--);
//	NVIC_DisableIRQ(SysTick_IRQn);
	disableSysTickInterrupt();
}

int main() {
	fourBytes = 0xdeadbeef;
	noArgFunc();

	initSysTick();
  waitForever();

	while(1) {
	}

	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;
}
