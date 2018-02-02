// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int BUTTON_yellow = 9;
int BUTTON_blue = 8;
int BUTTON_green = 13;
int BUTTON_red = 10;
int PTS = 0; // need to have 2 seperate couners for each player
int turnCount = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Player1 Player2 ");
}

//Minus button are interior buttons, green and red
void loop() {
    if(digitalRead(BUTTON_blue) == HIGH){
      delay(150);
      turnCount++;
      PTS = PTS + 1;
      if (turnCount / 2 % 2 == 0){
       //turn off this LED, light up the other LED
       //if one keep this LED on 
      }
      }else if (digitalRead(BUTTON_red) == HIGH){
        delay(150);
        PTS = PTS - 1;
      }
    if(digitalRead(BUTTON_yellow) == HIGH){
      delay(150);
      turnCount++;
      PTS = PTS - 1;
       if (turnCount / 2 % 2 == 0){
       //turn off this LED, light up the other LED
       //if one keep this LED on 
      }

    }else if (digitalRead(BUTTON_green) == HIGH){
      delay(150);
      PTS = PTS - 1;
    }
    
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
//  lcd.print(millis() / 1000);
  lcd.print(PTS);
  
//  delay(150);
}
