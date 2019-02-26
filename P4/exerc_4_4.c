// ====================================
// File name: exerc_4_4.c (or cpp)
// Date: 2019-02-20
// Group Number: 21
// Members That contributed:
// Jacob Olsson
// Victor Roman
// Members not present at the demonstration :
// Xxxxxxx
// Demonstration code: [<Ass code 7505> ]
// ======================================

/* *******************************
Program file : bit_manage_function.c
Peter Lundin / 2016-01-97
For test IO program function
******************************** */
//: code
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;

#define BOOL(x) (!(!(x)))

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) BOOL((a) & (1L << (b)))

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


void setBit(int *bits, int index, int b){
    if(b)
        BIT_SET(*bits, index);
    else
        BIT_CLEAR(*bits, index);
}


void sleep( int milisecond){
	 clock_t start_t = (clock() + (milisecond * CLOCKS_PER_SEC)/1000);
   for(;;)
		 if(clock() > start_t)
		 	return;
}

int random_inport(void){
	return rand() % 256;
}

void printport(int value){
	int i = 7;
  for(; i >= 0; i--)
         printf("  %d", BIT_CHECK(value, i));
	printf(" - port value : %d  \n", value);
}

void reverseArr(char *arr){
  char temp[NELEMS(arr)];
  char *ptr1 = &arr[NELEMS(arr)];
  char *ptr2 = &temp[NELEMS(arr)];

  for(; ptr1 > arr;){
    *ptr1 = *ptr2;
    ptr1--;
    ptr2--;
  }

}

//*************************************************************
// void prntnum(unsigned long n, int base, char sign, char *outbuf)
// int num         = number to be printed
// int base        = number base for conversion;  decimal=10,hex=16
// char sign       = signed or unsigned output
// char *outbuf    = buffer to hold the output number
// Author - olibiaz
//*************************************************************

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



void printKey(int value){

	if(BIT_CHECK(value, 6) == 0){
		int a = 0;

		for(int i = 0;i < 4;i++)
			setBit(&a, i, BIT_CHECK(value,i));

      if(a <= 15){
        char arr[100];
        intToHex(a , 16, ' ', arr);
        printf("%s  , %d key pressed \n" ,arr , a );
      }

	}

}

int main(){
	unsigned int port;
	srand(time(0));

	int nr = 0;
	for (;nr < 10;nr++){
	   port = random_inport();
     printport(port);
	   printKey(port);
	   sleep(500);
	}
	return(0);
}
