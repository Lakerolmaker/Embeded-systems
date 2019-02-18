#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long first = 0;
long second = 0;
double total = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7,6,5,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,2,1,0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
lcd.begin(16, 2);               // start lcd

lcd.clear();
lcd.setCursor(0, 0);
lcd.print('h');
}


void loop()
{

  customKey = customKeypad.getKey();
  switch(customKey){
  case '':
  break;
  case '1':
    lcd.print(1);
  break;
  case 'B':
    lcd.print("B");
  break;
  case 'C':
    lcd.print("C");
  break;
  case 'D':
    lcd.print("D");
  break;
  case '*':
    lcd.print("*");
  break;
  case '#':
    lcd.print("#");
  break;

}

}
