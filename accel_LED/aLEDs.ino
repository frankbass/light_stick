void ledLoop() {
  lis.read();      // get X Y and Z data at once

  int x = angleMath(lis.x);
  //  int x = lis.x;
  //  x /= 64;
  //  x += 128;
  //  if (x > 255) {
  //    x = 255;
  //  }
  //  if (x < 0) {
  //    x = 0;
  //  }

  int y = angleMath(lis.y);
  //  int y = lis.y;
  //  y /= 64;
  //  y += 128;
  int z = angleMath(lis.z);
  //  int z = lis.z;
  //  z /= 64;
  //  z += 128;

  //  Serial.print("x: ");
  //  Serial.print(x);
  //  Serial.print(", y: ");
  //  Serial.print(y);
  //  Serial.print(", z: ");
  //  Serial.print(z);
  //  Serial.println();

  //  minMax(x, y, y);
  leds[0] = CRGB(x, y, z); //Green, Red, Blue
  FastLED.show();
}

int angleMath(int angle) {
  angle /= 64;
  angle += 128;
  if (angle > 255) {
    angle = 255;
  }
  if (angle < 0) {
    angle = 0;
  }
  Serial.println(angle);
  return angle;
}
