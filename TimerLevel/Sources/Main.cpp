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

LevelDetector levelDetector;
Timer timer;

void doTimerTimeout(void*)
{
	greenLed()->toggle();
}

void doButtonPressed(void*)
{
	redLed()->toggle();
	timer.stop();
	timer.start(redLed()->value() ? 250 : 500);
}

int main()
{
	greenLed()->configure(PinFunctionOutput0);
	redLed()->configure(PinFunctionOutput0);


	levelDetector.setPin(button());
	levelDetector.setEdge(EdgeRising);
	levelDetector.onEvent().connect(doButtonPressed);
	levelDetector.open();

	timer.setInterval(500);
	timer.onTimeout().connect(doTimerTimeout);
	timer.start();

	Thread::run();

}
