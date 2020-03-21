/*
  Tapping.cpp - designed to detect single and double taps on the accelerometer.
  It shifts through modes for light behaviour: angle = RGB or flashing or brightness
  March 21, 2020
*/

#include "Arduino.h"
#include "Tapping.h"

Tapping::Tapping()
{
  _mode = 0;
  _lastTapped = 0;
}
void Tapping::tapping(uint8_t c) {
  int timeDiff = millis() - _lastTapped;
  short tapped;
  if (timeDiff > 100) {
    _lastTapped = millis();
    uint8_t click = c;
    if (click == 0) return;
    if (! (click & 0x30)) return;
    //  Serial.print("Click detected (0x"); Serial.print(click, HEX); Serial.print("): ");
    if (click & 0x10) {
      tapped = 1;

    }
    if (click & 0x20) {
      tapped = 2;
      //      mode -= 1;
    }
    if (tapped == 2) {
      Serial.print("double click");
      mode --;
    }
    else if (tapped == 1) {
      Serial.print("single click");
      mode ++;
    }

    mode += 4;
    mode = mode % 4;

    Serial.println();
    Serial.print("mode: "); Serial.println(mode);
    Serial.print("time: "); Serial.println(timeDiff);
    Serial.print("click: "); Serial.println(click);
    Serial.println();
    return;
  }
}
