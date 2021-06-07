
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int R1 = 6;
int L1 = 7;
int R2 = 8;
int L2 = 9;
int IR_IN = A5;
int IR_OUT = A4;
int IR_1 = A3;
int IR_2 = A2;
int IR_3 = A1;
int IR_4 = A0;
int BUZZ = 10;
int INPUT_GATE = 0; //INPUT GATE Button
int OUTPUT_GATE = 0; //OUTPUT GATE Button
void setup() {
    // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  Serial.begin(115200);
  digitalWrite(R1,HIGH);
  digitalWrite(L1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(IR_IN,LOW);
  digitalWrite(IR_OUT,LOW);
  digitalWrite(IR_1,LOW);
  
  digitalWrite(IR_2,LOW);
  digitalWrite(IR_3,LOW);
  digitalWrite(IR_4,LOW);
  digitalWrite(BUZZ,LOW);
  
  pinMode(R1, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(IR_IN, INPUT);
  pinMode(IR_OUT, INPUT);
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
}


void loop() {

  if(digitalRead(IR_1)==LOW)
  {
  lcd.setCursor(1, 0);
  lcd.print("SLOT1=F");
  }
  else
  {
  lcd.setCursor(1, 0);
  lcd.print("SLOT1=E"); 
  }
  if(digitalRead(IR_2)==LOW)
  {
  lcd.setCursor(12, 0);
  lcd.print("SLOT2=F");
  }
  else
  {
  lcd.setCursor(12, 0);
  lcd.print("SLOT2=E"); 
  }
  if(analogRead(IR_3)<350)
  {
  lcd.setCursor(1, 3);
  lcd.print("SLOT3=F");
  }
  else
  {
  lcd.setCursor(1, 3);
  lcd.print("SLOT3=E"); 
  }
  if(digitalRead(IR_4)==LOW)
  {
  lcd.setCursor(12, 3);
  lcd.print("SLOT4=F");
  }
  else
  {
  lcd.setCursor(12, 3);
  lcd.print("SLOT4=E"); 
  }
  if(digitalRead(IR_1)==LOW&&digitalRead(IR_2)==LOW&&digitalRead(IR_3)==LOW&&digitalRead(IR_4)==LOW)
  {
  lcd.setCursor(0, 2);
  lcd.print("  COME BACK LATTER");
  lcd.setCursor(0, 1);
  lcd.print("    PARKING FULL    ");
  }
  else
  {
  lcd.setCursor(0, 2);
  lcd.print("      WELCOME     ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING AVAILABLE");
  }
  
  if((digitalRead(IR_1)||digitalRead(IR_2)||digitalRead(IR_3)||digitalRead(IR_4))==HIGH)
  {
 // lcd.clear();
    
  INPUT_GATE = digitalRead(IR_IN);
  if (INPUT_GATE == HIGH) 
  {
    digitalWrite(BUZZ,HIGH);
    digitalWrite(R1, HIGH);
    delay(1000);
    digitalWrite(L1,HIGH);
    }
  else 
  {
    digitalWrite(BUZZ,LOW);
    digitalWrite(R1, LOW);
    delay(1000);
    digitalWrite(L1,LOW);
    }
  }
  
    OUTPUT_GATE = digitalRead(IR_OUT);
  if (OUTPUT_GATE == HIGH) {
    digitalWrite(BUZZ,HIGH);
    digitalWrite(R2, HIGH);
    delay(1000);
    digitalWrite(L2,HIGH);
    }
  else 
    {
    digitalWrite(BUZZ,LOW);
    digitalWrite(R2, LOW);
    delay(1000);
    digitalWrite(L2,LOW);
    }

}
