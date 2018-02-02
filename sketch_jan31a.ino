

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int BUTTON_r = 9;
int BUTTON_g = 8;
int PTS = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
    if(digitalRead(BUTTON_g) == HIGH && digitalRead(BUTTON_r)== LOW){
      delay(150);
      PTS = PTS + 1;
//      delay(150);
    }
    if(digitalRead(BUTTON_r) == HIGH && digitalRead(BUTTON_g) == LOW){
      delay(150);
      PTS = PTS - 1;
//      delay(150);
    }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
//  lcd.print(millis() / 1000);
  lcd.print(PTS);
//  delay(150);
}
