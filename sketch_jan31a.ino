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
int P1SET = 0;
int P2SET = 0;
int P1GAME = 0;
int P2GAME = 0;
int 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(7, 0);
  lcd.print("-");
  lcd.setCursor(7, 1);
  lcd.print("-");
}

void loop() {
  // Increments score for player 1
    if(digitalRead(BUTTON_blue) == HIGH){
      P1SET++;
      delay(500);
    } //Decrements score for player 1
    else if(digitalRead(BUTTON_red) == HIGH && P1SET > 0){
      P1SET--;
      delay(500);
    }
  // Increments score for player 2
    if(digitalRead(BUTTON_yellow) == HIGH){
      P2SET++;
      delay(500);
    } //Decrements score for player 2
    else if(digitalRead(BUTTON_green) == HIGH && P2SET > 0){
      P2SET--;
      delay(500);
    }

// Increments the gamescore of player 1
    if(P1SET == 11){
      P1SET = 0;
      P2SET = 0;
      P1GAME++;
    }
// Increments the gamescore of player 2
    if(P2SET == 11){
      P1SET = 0;
      P2SET = 0;
      P2GAME++;
    }


    
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(5, 0);
  lcd.print(P1GAME);
  lcd.setCursor(13, 0);
  lcd.print(P2GAME);  
  lcd.setCursor(5, 1);
  lcd.print(P1SET);
  lcd.setCursor(13, 1);
  lcd.print(P2SET);
}
