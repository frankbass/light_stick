/*
  Tapping.cpp - designed to detect single and double taps on the accelerometer.
  It shifts through modes for light behaviour: angle = RGB or flashing or brightness
  March 21, 2020
*/

#ifndef Tapping_h
#define Tapping_h

#include "Arduino.h"

class Tapping
{
  public:
      Tapping();
      void tapping();
  private:
      int _lastTapped;
      int _mode;
};

#endif
