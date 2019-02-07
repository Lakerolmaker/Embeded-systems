// passed 7630
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


void copyString( char *source, char *destination ,int size){
//pointers get address for source and destination arrays
  char *ptr1 = source , *ptr2 = destination;
//modified for loop, no need for initalizer, go until actual size of address
  for(; ptr1 < &source[size];){
    //assign desination[x] value of source[x]
    *ptr2 = *ptr1;
  // increase
    ptr1++;
    ptr2++;
  }

}

int main(void){
  //create two char arrays to store sentences
  char src[100];
  char dest[100];
//take the sentence
  printf("Input a sentence to be copied : ");
  scanf("%[^\n]%*c", src);

  copyString(src, dest , NELEMS(src));
  //åromt semtemce
  printf("Original string: %s \n" , src);
  printf("Final copied string: %s \n", dest);

   return(0);
}
