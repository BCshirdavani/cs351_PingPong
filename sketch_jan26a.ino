int LED = 12;
int BUTTON = 4;
int COUNTER = 0;
bool pressed;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop(){
  if(digitalRead(BUTTON) == HIGH && !pressed){
      //digitalWrite(LED, HIGH);
      COUNTER++;
      //delay(1000);
      pressed = true;
    }
    else{
      digitalWrite(LED,LOW);
    }
    if(digitalRead(BUTTON) == LOW){
      pressed = false;
    }

    if (COUNTER > 5){
      digitalWrite(LED, HIGH);
      }
    
}

