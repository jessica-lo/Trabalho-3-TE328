#ifndef DISPOSITIVOS_H
#define DISPOSITIVOS_H

#include <Arduino.h>

int getDist(int echo, int trig);
void lightLed(int val, const int* led);

#endif
