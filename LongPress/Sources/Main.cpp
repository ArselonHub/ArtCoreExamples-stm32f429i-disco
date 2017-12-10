/*
 * Main.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: denizcan
 */

#include <Art/Bsp.h>
#include <Art/LevelDetector.h>
#include <Art/Timer.h>
#include <Art/Thread.h>

using namespace Art;

LevelDetector buttonDetector;
Timer longPressTimer;

void doLongPressTimerTimeout(void*)
{
	redLed()->set();
}

void doButtonLevelChanged(void*)
{
	if (buttonDetector.level())
	{
		// button is pressed
		greenLed()->set();
		longPressTimer.start();
	}
	else
	{
		// button released
		greenLed()->clear();
		redLed()->clear();
		longPressTimer.stop();
	}
}

int main()
{
	greenLed()->configure(PinFunctionOutput0);
	redLed()->configure(PinFunctionOutput0);

	buttonDetector.setPin(button());
	buttonDetector.setEdge(EdgeBoth);
	buttonDetector.onEvent().connect(doButtonLevelChanged);
	buttonDetector.open();

	longPressTimer.setInterval(3000);
	longPressTimer.onTimeout().connect(doLongPressTimerTimeout);
	longPressTimer.setAutoReset(false);

	Thread::run();
}
