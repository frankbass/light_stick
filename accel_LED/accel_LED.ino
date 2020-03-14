// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

float minX;
float maxX;
float minY;
float maxY;
float minZ;
float maxZ;

#include <FastLED.h>
#define NUM_LEDS 1 //number of LEDs
#define LED_PIN 13 //LED pin
CRGB leds[NUM_LEDS];


void setup(void) {
  Serial.begin(9600);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("LIS3DH test!");

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());
  Serial.println("G");


  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);

  //    leds[0] = CRGB(0,0,255); //Green, Red, Blue
  //    FastLED.show();
  leds[0] = CRGB(0, 0, 0); //Green, Red, Blue
  FastLED.show();
}

void loop() {
  lis.read();      // get X Y and Z data at once
  int x = lis.x;
  x /= 64;
  x += 128;
  Serial.print("x: ");
  Serial.print(x);
  int y = lis.y;
  y /= 64;
  y += 128;
  Serial.print(", y: ");
  Serial.print(y);
  int z = lis.z;
  z /= 64;
  z += 128;
  Serial.print(", z: ");
  Serial.print(z);
  Serial.println();

  minMax(x, y, y);
  leds[0] = CRGB(x, y, z); //Green, Red, Blue
  FastLED.show();

  //  Serial.print("X:  "); Serial.print(lis.x);
  //  Serial.print("  \tY:  "); Serial.print(lis.y);


  //  Serial.print("  \tZ:  "); Serial.print(lis.z);

  /* Or....get a new sensor event, normalized */
  //  sensors_event_t event;
  //  lis.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  //  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  //  Serial.print(" \tY: "); Serial.print(event.acceleration.y);
  //  Serial.println();
  //  minMax(event.acceleration.y);
  //  Serial.print(" \tZ: "); Serial.print(event.acceleration.z);
  //  Serial.println(" m/s^2 ");

  //  Serial.println();
  // Serial.println(count);
  //  count += 1;;
  delay(200);
}

void minMax(int x, int y, int z) {
   if (x > maxX) {
    maxX = x;
  }
  if (x < minX) {
    minX = x;
  }
  Serial.print("Min X "); Serial.print(minX);
  Serial.print(", Max X "); Serial.println(maxX);
   if (y > maxY) {
    maxY = y;
  }
  if (y < minY) {
    minY = y;
  }
  Serial.print("Min Y "); Serial.print(minY);
  Serial.print(", Max Y "); Serial.println(maxY);

  if (z > maxZ) {
    maxZ = z;
  }
  if (z < minZ) {
    minZ = z;
  }
  Serial.print("Min Z "); Serial.print(minZ);
  Serial.print(", Max Z "); Serial.println(maxZ);
  Serial.println();
}

