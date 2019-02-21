// code : 21917
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

unsigned char *portDDRD;
unsigned char *portwrite;
unsigned char *portread;

void portSetup(){
portDDRD=(unsigned char *)0x2a;
portwrite=(unsigned char *)0x2b;
portread=(unsigned char *)0x29;
*portDDRD  = B11110000;
}

void setup(){
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0, 0);
portSetup();
}

void firstRow(){

  *portwrite = B01110000;
  if(*portread == B01110001 || *portread == B01110000){
    *portDDRD  = B00001111;

    *portwrite = B00001000;
    if(*portread == B11111000)
      lcd.print('0');

    *portwrite = B00000100;
    if(*portread == B11110100)
      lcd.print('1');

    *portwrite = B00000010;
    if(*portread == B11110010)
      lcd.print('2');

    *portwrite = B00000001;
    if(*portread == B11110001)
      lcd.print('3');
  }
  *portDDRD  = B11110000;
}

void secondRow(){

  *portwrite = B10110000;
  if(*portread == B10110001 || *portread == B10110000){
    *portDDRD  = B00001111;

    *portwrite = B00001000;
    if(*portread == B11111000)
      lcd.print('4');

    *portwrite = B00000100;
    if(*portread == B11110100)
      lcd.print('5');

    *portwrite = B00000010;
    if(*portread == B11110010)
      lcd.print('6');

    *portwrite = B00000001;
    if(*portread == B11110001)
      lcd.print('7');
  }
  *portDDRD  = B11110000;
}

void thirdRow(){

  *portwrite = B11010000;
  if(*portread == B11010001 || *portread == B11010000){
    *portDDRD  = B00001111;

    *portwrite = B00001000;
    if(*portread == B11111000)
      lcd.print('8');

    *portwrite = B00000100;
    if(*portread == B11110100)
      lcd.print('9');

    *portwrite = B00000010;
    if(*portread == B11110010)
      lcd.print('A');

    *portwrite = B00000001;
    if(*portread == B11110001)
      lcd.print('B');
  }
  *portDDRD  = B11110000;
}

void fourthRow(){

  *portwrite = B11100000;
  if(*portread == B11100001 || *portread == B11100000){
    *portDDRD  = B00001111;

    *portwrite = B00001000;
    if(*portread == B11111000)
      lcd.print('C');

    *portwrite = B00000100;
    if(*portread == B11110100)
      lcd.print('D');

    *portwrite = B00000010;
    if(*portread == B11110010)
      lcd.print('E');

    *portwrite = B00000001;
    if(*portread == B11110001)
      lcd.print('F');
  }
  *portDDRD  = B11110000;
}

//: The loop, runns evey milisecond.
void loop(){

   delay(1000);

   firstRow();
   secondRow();
   thirdRow();
   fourthRow();

}
