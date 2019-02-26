// ====================================
// File name: exerc_4_2.c (or cpp)
// Date: 2019-02-20
// Group Number: 21
// Members That contributed:
// Jacob Olsson
// Victor Roman
// Members not present at the demonstration :
// Xxxxxxx
// Demonstration code: [<Ass code 26051> ]
// ======================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;

#define BOOL(x) (!(!(x)))

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(var,pos) (var >> pos) & 1

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


 unsigned long hex2int(char *a, unsigned int len){
     int i = 0;
     unsigned long val = 0;
     for(;i<len;i++)
        if(a[i] <= 57)
         val += (a[i]-48)*(1<<(4*(len-1-i)));
        else
         val += (a[i]-55)*(1<<(4*(len-1-i)));
     return val;
}

 void setBit(int *bits, int index, int b){
     if(b)
         BIT_SET(*bits, index);
     else
         BIT_CLEAR(*bits, index);
 }

 void printbits(int value){
 	int i = 7;
   for(; i >= 0; i--)
          printf("%d  ", BIT_CHECK(value, i));
   printf("\n");
 }


int main(void){

printf("input hex : ");
char hex[100];
scanf("%s",hex);

int bits = hex2int(hex , strlen(hex));

int one = 0;
int two = 0;
int three = 0;
int four = 0;
int five = 0;

setBit(&one , 0 , BIT_CHECK(bits ,0));

setBit(&two , 0 , BIT_CHECK(bits ,1));


setBit(&three , 0 , BIT_CHECK(bits ,2));
setBit(&three , 1 , BIT_CHECK(bits ,3));


setBit(&four , 0 , BIT_CHECK(bits ,4));
setBit(&four , 1 , BIT_CHECK(bits ,5));
setBit(&four , 2 , BIT_CHECK(bits ,6));


setBit(&five , 0 , BIT_CHECK(bits ,7));

printbits(bits);
printf("Value from hex : %d \n" , bits);
printf("Name Value \n");
printf("----------------------------- \n");
printf("engine_on %d \n", five);
printf("gear_pos %d \n", four);
printf("key_pos %d \n", three);
printf("brake1 %d \n", two);
printf("brake1e2 %d \n", one);

}
