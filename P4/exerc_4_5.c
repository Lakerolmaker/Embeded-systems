#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {7,6,5,4};
byte colPins[COLS] = {3,2,1,0};

//: Set's all collums exept one to HIGH
void setCol(int col_num){
  for(int x = 0; x < COLS; x++){
    if(x == col_num)
      digitalWrite(rowPins[x],LOW);
    else
      digitalWrite(rowPins[x],HIGH);
  }
}

//: Get's the char for the corresponding key.
char read_key(){
 //: Loop thur all the rows chaning one to low incramentally.
 for(int y = 0;y < ROWS;y++){
   //: Sets all rows exept for one to HIGH
   setCol(y);
   for(int x = 0; x < COLS; x++){
     //: checks for the one key that collum that is off. which signa
     if(digitalRead(colPins[x]) == 0)
       return keys[y][x];
   }
 }
 //: Returns 0 if no key was found
 return 0;
}

//: Setup for the ports.
void resetKeys(){
  for(int i = 0; i < ROWS; i++){
   pinMode(rowPins[i],OUTPUT);
   digitalWrite(rowPins[i],HIGH);
  }
  for(int i = 0; i < ROWS; i++){
    pinMode(colPins[i],INPUT_PULLUP);
  }
}

//: Setup
void setup(){
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0, 0);
resetKeys();
}

//: char for storing the char.
char customKey;

//: The loop, runns evey milisecond.
void loop(){
   delay(1000);
   customKey = read_key();
   if(customKey != 0)
    lcd.print(customKey);
}
