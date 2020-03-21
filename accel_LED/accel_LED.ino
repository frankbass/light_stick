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


#include <FastLED.h>
#define NUM_LEDS 1 //number of LEDs
#define LED_PIN 13 //LED pin
CRGB leds[NUM_LEDS];

// Adjust this number for the sensitivity of the 'click' force
// this strongly depend on the range! for 16G, try 5-10
// for 8G, try 10-20. for 4G try 20-40. for 2G try 40-80

unsigned long count = 0;


#define CLICKTHRESHHOLD 30



class Tapping
{
    int mode;
    int lastTapped;

  public:
    Tapping(int m, int lT)
    {
      mode = m;
      lastTapped = lT;
    }
    void tapping() {
      int timeDiff = millis() - lastTapped;
      short tapped;
      if (timeDiff > 100) {
        lastTapped = millis();
        uint8_t click = lis.getClick();
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
};




Tapping one(0,0);

void setup(void) {
  Serial.begin(9600);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());
  Serial.println("G");


  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);

  leds[0] = CRGB(0, 0, 0); //Green, Red, Blue
  FastLED.show();

  // 0 = turn off click detection & interrupt
  // 1 = single click only interrupt output
  // 2 = double click only interrupt output, detect single click
  // Adjust threshhold, higher numbers are less sensitive
  lis.setClick(2, CLICKTHRESHHOLD);
  delay(80);
}
bool once = true;
void loop() {
//  tapping();
one.tapping();
  if (millis() % 200 <= 20) {
    if (once) {
      ledLoop();
      
//      Serial.println(count);
      count ++;
      once = false;
    }
  }
  else {
    once = true;
  }
}
