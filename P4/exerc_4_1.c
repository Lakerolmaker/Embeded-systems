#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 25967
typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;

#define BOOL(x) (!(!(x)))

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(var,pos) (var >> pos) & 1


#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void printHexChar(unsigned char value){
    unsigned char lower = value & 0xf; // Use binary 'and' to mask the lower byte
    unsigned char upper = (value & 0xf0) >> 4; // Use binary 'and' to mask upper byte

    if(lower >= 10) // If lower is in range [10-15], than add a value [0-5] on 'a'.
        lower = 'a' + (lower - 10);
    else
        lower = lower + '0'; // It's in range [0-9], so we have to add it to '0'.

    if(upper >= 10) // Same as lower
        upper = 'a' + (upper - 10);
    else
        upper = upper + '0';

    printf("%c%c",upper,lower); // Print out the hexadecimal number
}

void printbits(int value){
    int i = 7;
    for(; i >=0; i--)
        printf("%d  ", BIT_CHECK(value, i));
    printf("\n");
}

void assignbits(int value, int arr[]){
    int i = 0;
    for(; i <8; i++)
    arr[i] = BIT_CHECK(value, i);
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

void terminate(){
  printf("Wrong arguments or exceeded values");
  exit(1);
}

int main(int argc, char *argv[]){

    char bits;
    int one = getInt(argv[1]);
    int two = getInt(argv[2]);
    int three = getInt(argv[3]);
    int four = getInt(argv[4]);
    int five = getInt(argv[5]);


//    int one = 1;
//    int two = 1;
//    int three = 2;
//    int four = 2;
//    int five = 1;

  if (one+two+three+four+five>9 || argc > 6) {
    printf("Wrong arguments or exceeded values");
    exit(1);

  }
    if(one < 2){
        setBit(&bits , 0 , BIT_CHECK(one ,0));
    }
    else {terminate();;}
    if(two < 2){
        setBit(&bits , 1 , BIT_CHECK(two ,0));
    }
    else {terminate();}
    if(three < 3){
        setBit(&bits , 2 , BIT_CHECK(three ,0));
        setBit(&bits , 3 , BIT_CHECK(three ,1));
    }
    else{terminate();}
    if(four < 5){
        setBit(&bits , 4 , BIT_CHECK(four ,0));
        setBit(&bits , 5 , BIT_CHECK(four ,1));
        setBit(&bits , 6 , BIT_CHECK(four ,2));
    }
    else {terminate();}
    if(five < 2)
    {
        setBit(&bits , 7 , BIT_CHECK(five ,0));
    }
    else {terminate();}


    char arr[100];
    int arr1[7];


    printbits(bits);
    printf("\n");
    printHexChar(bits);
    printf("\n");
    printf("char value : %c \n" , bits);
    printf("Number value : %d \n" , 10);
    printf("Hex value : %s \n" , arr);

}
