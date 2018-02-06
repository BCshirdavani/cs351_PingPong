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
int all_pt_counter;   // use all_pt_counter to change LED colors for servers
int setGAP;           // setGAP used to show piont margin
bool tightSET;        // tightSET true if set point = 10, and within setGAP of < 2
int MatchCount;       // tracks # of matches... play 5 matches in a game
                      // also use this to switch score sides on LCD between matches
int LED_red = 7;
int LED_blue = 6;
bool redTURN;         // controls when to switch blue/red LED's



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(7, 0);
  lcd.print("-");
  lcd.setCursor(7, 1);
  lcd.print("-");
  all_pt_counter = P1SET + P2SET; 
  setGAP = abs(P1SET - P2SET);
  tightSET = false;
  MatchCount = 0;
}




void loop() {

  
  // Increments score for player 1
    if(digitalRead(BUTTON_blue) == HIGH){
      P1SET++;
      setGAP = abs(P1SET - P2SET);
      // set the boolean for tightSET here
      if(( P1SET >= 10 || P2SET >=10) && setGAP < 2){
        tightSET = true;
        }
      else tightSET = false;
      all_pt_counter = P1SET + P2SET;     
      delay(500);
    } //Decrements score for player 1
    else if(digitalRead(BUTTON_red) == HIGH && P1SET > 0){
      P1SET--;
      setGAP = abs(P1SET - P2SET);
      delay(500);
    }
  // Increments score for player 2
    if(digitalRead(BUTTON_yellow) == HIGH){
      P2SET++;
      setGAP = abs(P1SET - P2SET);
      all_pt_counter = P1SET + P2SET; 
      // set the boolean for tightSET here
      if(( P1SET >= 10 || P2SET >=10) && setGAP < 2){
        tightSET = true;
        }
      else tightSET = false;
      delay(500);
    } //Decrements score for player 2
    else if(digitalRead(BUTTON_green) == HIGH && P2SET > 0){
      P2SET--;
      setGAP = abs(P1SET - P2SET);
      delay(500);
    }



// Increments the gamescore of player 1
    if((P1SET >= 11) && (tightSET == false) && (P1SET > P2SET)){
      P1SET = 0;
      P2SET = 0;
      P1GAME++;
      MatchCount++;
      lcd.clear();         // clear screen to drop bad legacy digit
    } 
// Increments the gamescore of player 2
    if((P2SET >= 11) && (tightSET == false) && (P2SET > P1SET)){
      P1SET = 0;
      P2SET = 0;
      P2GAME++;
      MatchCount++;
      lcd.clear();       // clear screen to drop bad legacy digit
    }



  // control LED lights
  redTURN = (((all_pt_counter) / 2) % 2);
  if (!tightSET){
      if (redTURN){
      digitalWrite(LED_red,HIGH);
      digitalWrite(LED_blue,LOW);
      }
      else {
      digitalWrite(LED_red,LOW);
      digitalWrite(LED_blue,HIGH);
      } 
  }
  else {
      if(all_pt_counter % 2){
          digitalWrite(LED_red,HIGH);
          digitalWrite(LED_blue,LOW);
        }
      else{
          digitalWrite(LED_red,LOW);
          digitalWrite(LED_blue,HIGH);
        }
      }
    

    
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
      // add logic here, using if statement and (MatchCount % 2)
      // to shift the locations of player scores
      // switching sides between matches, up through match 5.
      if ((MatchCount % 2) && (MatchCount < 5) ){
            lcd.setCursor(5, 0);
            lcd.print(P2GAME);
            lcd.setCursor(14, 0);
            lcd.print(P1GAME);  
            lcd.setCursor(5, 1);
            lcd.print(P2SET);
            lcd.setCursor(14, 1);
            lcd.print(P1SET);
            lcd.setCursor(1, 0);
            lcd.print("p2:");
            lcd.setCursor(10, 0);
            lcd.print("p1:");
        }
        else if (MatchCount < 5){
            lcd.setCursor(5, 0);
            lcd.print(P1GAME);
            lcd.setCursor(14, 0);
            lcd.print(P2GAME);  
            lcd.setCursor(5, 1);
            lcd.print(P1SET);
            lcd.setCursor(14, 1);
            lcd.print(P2SET);
            lcd.setCursor(1, 0);
            lcd.print("p1:");
            lcd.setCursor(10, 0);
            lcd.print("p2:");
          }
         else if ((MatchCount >= 5)){
            if (P1GAME > P2GAME){
                lcd.clear();
                lcd.setCursor(1, 0);
                lcd.print("P1 WINS");
//                delay(1000);
                lcd.setCursor(1, 1);
                lcd.print("press reset");
              }
              else{
                lcd.clear();
                lcd.setCursor(1, 0);
                lcd.print("P2 WINS");
//                delay(1000);
                lcd.setCursor(1, 1);
                lcd.print("press reset");
            }
          }

}
