// ------- Program skeleton for exerc 4.3 AT ----
// ------- File skeleton_4_3_AT.txt ----------------
//#include <avr/io.h>   Not needed
#include <util/delay.h>

#define REG8(x) *((unsigned char *) (x))     // A macro to use for IO R/W
#define OUT_PORTD 	0x2B
#define IN_PORTB  	0x23
#define DDR_D     	0x2A
#define DDR_B      	8
#define BLINK_DELAY_MS 	800

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define INT_BITS 8

int bits;

int main (void)
{
    unsigned char code;
    unsigned char incode;
    // If use of simple pointer and not macro REG8
    //unsigned char *portd;
    //portd=(unsigned char *)0x002B; // Must do as this
    //*portd=0;  If use of pointer for IO R/W
    //  set  PORTD for output, set bit gives out
    REG8(DDR_D)=0xFF;
    //  set  PORTB for input, clr bit gives inbit
    REG8(DDR_B)=0x00;


    pinMode(8, INPUT);
    pinMode(DDR_D, OUTPUT);

    writeOut(3);


  while(1){

    int val = digitalRead(8);
    if(val == 0){
      ror();
    }
    _delay_ms(BLINK_DELAY_MS); // In util/delay.h
 }
}

void update_lamp(){
  int i = 0;
  for(; i < 8;i++){
      digitalWrite(i, CHECK_BIT(bits , i));
    }

}

void ror(){

rotateRight(&bits , 1);
update_lamp();

}

int rotateRight(int *num, unsigned int rotation)
{
    int DROPPED_LSB;

    // The effective rotation
    rotation %= INT_BITS;


    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get LSB of num before it gets dropped
        DROPPED_LSB = *num & 1;

        // Right shift num by 1 and
        // Clear its MSB
        *num = (*num >> 1) & (~(1 << INT_BITS));

        // Set its dropped LSB as new MSB
        *num = *num | (DROPPED_LSB << INT_BITS);
    }

    return *num;
}


void writeOut(int in){
  bits = in;
}
