/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "AssemblyModule.h"
#include "Led.h"
#include "UserLed.h"

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

	while(1) {
		turnOnLED(LED3);
		wait();
		turnOffLED(LED3);
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
