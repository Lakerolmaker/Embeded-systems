/*====================================
 * File name: exerc_5_1.ino
 * Date: 2019-02-26
 * Group Number: 21 & 15
 * Members That contributed: Jacob Olson, Victor Olsson, Jonatan Sundberg , Albin Gustafsson, Nuria Cara Navas
 * Demonstration code: [<37601>]
 ======================================*/

//       CA1 G  F  A  B
//        |  |  |  |  |      -> pins and segments they control
//   ---------    ---------
//   |   A   |    |   A   |
//  F|       |B  F|       |B
//   |---G---|    |---G---|
//  E|       |C  E|       |C
//   |   D   |    |   D   |
//   ---------    ---------
//        |  |  |  |  |      -> pins and segments they control
//        D  DP E  C CA2


#define A 6
#define B 8
#define C 7
#define D 2
#define E 3
#define F_SEG 4
#define G 5

#define CA1 13 
#define CA2 12 

#define OFF LOW
#define ON HIGH

// Pin for temperature reading
const int S1 = A5;


// Variable for storing the maximum temperature
int tempMAX = -100;

//State of DIP switch 1
//int s1state = HIGH;   //HIGH means off, LOW means on (INPUT_PULLUP)

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F_SEG, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);
  
  pinMode(S1, INPUT);

  Serial.begin(9600);
}

int del = 6000; // fine adjustment for clock
unsigned long time;

 long timeNow = millis();
 long timePassed = timeNow - time;

void clearLEDS()  // clear the screen
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F_SEG, LOW);
  digitalWrite(G, LOW);
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, LOW);
  timePassed = millis();
}


int val = 0;
void loop () {

    val = analogRead(A5);
    int temp = val * 0.48828125;
    displaynumber(temp);
    
    Serial.print("Current temperature is: ");
    Serial.println(temp);
    
}

void displaynumber(int temp){

  if(temp >= -9 && temp < 0){
      selectSecondDigit();
      drawMinus();
      selectFirstDigit();
      drawNumber(temp*(-1));
    }
    else if(temp>=0 && temp<10){
      selectFirstDigit();
      drawNumber(temp);
      delay(1000);
    }
    else if(temp>=10){
      selectSecondDigit();
      drawNumber(temp/10);
      delay(20);
      selectFirstDigit();
      drawNumber(temp%10);
    }
  
}

// Selects the first digit
void selectFirstDigit(){
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, LOW);
}

// Selects the second digit
void selectSecondDigit(){
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, HIGH);
}

// Draws a minus on the selected digit
void drawMinus(){
  digitalWrite(A, OFF);
  digitalWrite(B, OFF);
  digitalWrite(C, OFF);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F_SEG, OFF);
  digitalWrite(G, ON);
}

// Draws numbers 0-9 on selected digit
void drawNumber(int number){
  switch (number){
    case 0:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, OFF);
        break;
    case 1: //
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, OFF);
        break;
    case 2:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, OFF);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, ON);
        break;
    case 3:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, ON);
        break;
    case 4:
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 5:
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 6: //
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 7:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, OFF);
        break;
    case 8: //
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 9:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
  }
}

