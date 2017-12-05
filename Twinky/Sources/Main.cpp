/*
 * Main.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: denizcan
 */

#include <Art/Bsp.h>
#include <Art/Thread.h>

using namespace Art;

Thread blinkyThread;

void blinkThreadFn(Int period)
{
	redLed()->configure(PinFunctionOutput0);
	while (1)
	{
		redLed()->toggle();
		sleep(period);
	}
}

int main()
{
	// starts the thread with default settings, passing 300 as period. Note that
	// blinkyThread starts immediately..
	blinkyThread.start(blinkThreadFn, 300);

	greenLed()->configure(PinFunctionOutput0);
	while (1)
	{
		greenLed()->toggle();
		sleep(500);
	}
}
