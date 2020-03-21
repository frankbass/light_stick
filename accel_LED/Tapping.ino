/*
class Tapping
{
    
  public:
    Tapping()
    {
      int mode = 0;
      int lastTapped = 0;
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
*/
