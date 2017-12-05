#include <Art/SerialPort.h>
#include <Art/Pin.h>
#include <Art/Timer.h>
#include <Art/Thread.h>
#include <Art/String.h>
#include <Art/Bsp.h>

using namespace Art;

SerialPort serialPort;
Timer timer;

Word count = -20;

void doDataTransmitted(void*)
{
	led()->toggle();
} 

void doTimeout(void*)
{
	led()->toggle();
	serialPort.writeLine(String("Count: %0").arg(count, -6, '0'));
	count++;
}

int main()
{
	led()->configure(PinFunctionOutput0);
	serialPort.setPort(uart());
	serialPort.setBaud(Baud115200);
	serialPort.onDataTransmitted().connect(doDataTransmitted);
	serialPort.open();
	
	timer.onTimeout().connect(doTimeout);
	timer.start(100);
	Thread::run();
}
