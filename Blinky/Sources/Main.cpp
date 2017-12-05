/*
 * Main.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: denizcan
 */

#include <Art/Bsp.h>
#include <Art/Thread.h>

using namespace Art;

int main()
{
	led()->configure(PinFunctionOutput0);
	while (1)
	{
		led()->toggle();
		sleep(500);
	}
}
