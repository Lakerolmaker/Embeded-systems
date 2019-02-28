/* ====================================
File name: exerc_5_1.ino
Date: 2019-02-26
Group Number:
Members That contributed:
Jacob Olsson
Victor Roman
Albin Gustafsson
Jonatan Sundberg
Nuria Cara Navas
Demonstration code: [<Ass code 7037> ]
====================================== */


#define A 6
#define B 8
#define C 7
#define D 2
#define E 3
#define F 4
#define G 5

#define CA1 13
#define CA2 12

#define D1 11
#define D2 10

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);

  pinMode(D1, INPUT);
  pinMode(D2, INPUT);

  Serial.begin(9600);
}

long previousMillis = millis();
int timeHasPassed(long miliSec){
  if (millis() - previousMillis >= miliSec) {
    previousMillis = millis();
    return true;
  }else{
    return false;
  }
}


int temp = 0;
int val = 0;
int maxtemp = 0;
void loop() {

    if(timeHasPassed(500)){
       val = analogRead(A5);
       temp = val * 0.48828125;

       if(temp > maxtemp){
        maxtemp = temp;
       }
    }

    if(getMode() == 1){
       displayNumber(temp);
    }else if(getMode() == 0){
       displayNumber(maxtemp);
    }else{
      displayErr();
    }
}

int getMode(){
  if(normalMode() && !maxMode()){
         return 0;
  }else if(!normalMode() && maxMode()){
        return 1;
  }else{
        return -1;
  }
}

int maxMode(){
  if(digitalRead(D1) == 1){
    return true;
  }else{
    return false;
  }
}

int normalMode(){
  if(digitalRead(D2) == 1){
    return true;
  }else{
    return false;
  }
}

void displayNumber(int temp){
    if(temp>=0 && temp<10){
      selectDigit(1);
      displayDigit(temp);
      delay(1000);
    }else if(temp>=10){
      selectDigit(2);
      displayDigit(temp/10);
      delay(1);
      selectDigit(1);
      displayDigit(temp%10);
      delay(1);
    }
}

void selectDigit(int digit){
  if(digit == 1){
     digitalWrite(CA1, HIGH);
     digitalWrite(CA2, LOW);
  }else if(digit == 2){
    digitalWrite(CA1, LOW);
    digitalWrite(CA2, HIGH);
  }
}

void displayErr(){
  selectDigit(2);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(1);
  selectDigit(1);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(1);
}

void displayDigit(int number){
  switch (number){
    case 0:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, LOW);
    break;
    case 1:
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
    break;
    case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
    break;
    case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
    break;
    case 4:
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    break;
    case 5:
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    break;
    case 6:
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    break;
    case 7:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
    break;
    case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    break;
    case 9:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    break;
  }
}
