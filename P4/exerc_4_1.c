#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;

#define BOOL(x) (!(!(x)))

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(var,pos) (var >> pos) & 1


#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


void printbits(int value){
	int i = 7;
  for(; i >= 0; i--)
         printf("%d  ", BIT_CHECK(value, i));
  printf("\n");
}

int getInt(char *c){
  return atoi(c);
}

void setBit(char *bits, int index, int b){
    if(b)
        BIT_SET(*bits, index);
    else
        BIT_CLEAR(*bits, index);
}

void intToHex(int num, int base, char sign, char *outbuf){

    int i = 12;
    int j = 0;

    do{
        outbuf[i] = "0123456789ABCDEF"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }

    while( ++i < 13){
       outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;

}

int main(int argc, char *argv[]){

        char bits;
        int one = getInt(argv[1]);
        int two = getInt(argv[2]);
        int three = getInt(argv[3]);
        int four = getInt(argv[4]);
        int five = getInt(argv[5]);


        if(one < 2){
          setBit(&bits , 0 , BIT_CHECK(one ,0));
        }
        if(two < 2){
          setBit(&bits , 1 , BIT_CHECK(two ,0));
        }
        if(three < 3){
          setBit(&bits , 2 , BIT_CHECK(three ,0));
          setBit(&bits , 3 , BIT_CHECK(three ,1));
        }
        if(four < 5){
          setBit(&bits , 4 , BIT_CHECK(four ,0));
          setBit(&bits , 5 , BIT_CHECK(four ,1));
          setBit(&bits , 6 , BIT_CHECK(four ,2));
        }
        if(five < 2)
        {
          setBit(&bits , 7 , BIT_CHECK(five ,0));
        }


        char arr[100];
        int number = bits;
        if(number < 0){
          number *= -1;
        }
        intToHex(number , 16, ' ', arr);

        printbits(bits);
        printf("char value : %c \n" , bits);
        printf("Number value : %d \n" , number);
        printf("Hex value : %s \n" , arr);

}
