# ArtCoreExamples-stm32f429i-disco
Art Core Library Examples

This package includes example the evolution projects for STM32F429I-DISCO board and 
variants.. To compile this examples you also need relevant ArtCore library:

https://github.com/ArselonHub/ArtCore-stm32f4

Please read the README.md on that package before continuing..

The examples are as follows:

## Blinky-stm32f429i-disco

A very simple program that blinks a Led.. It configures a GPIO that is
connected to Led, provided by Art/Bsp.h header.. Than toggles it
in a loop.

## Twinky-stm32f429i-disco

A simple program that blinks two led in two different threads.. Like
Blinky, it configures GPIO's that are connected to Leds, and toggles
them.. All is done in two different threads.. 

Note that  in ArtCore, int main() is called by main thread. 

## SerialPort-stm32f429i-disco

Configures a serial port on uart, creates a timer that ticks in every
100ms. In each timeout doTimer(void*) function toggles a led and writes 
a string on serial port. When the transfer is completed, serialPort 
calls doDataWritten(void*) and the function toggles led again.

That way Led is on from the beginning to the end of the transmission..
