void ledLoop() {
  lis.read();      // get X Y and Z data at once
  int x = lis.x;
  x /= 64;
  x += 128;
  int y = lis.y;
  y /= 64;
  y += 128;
  int z = lis.z;
  z /= 64;
  z += 128;
  
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

