#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString( char *source, char *destination){

  char *ptr1 = source , *ptr2 = destination;

  for(; ptr1 < &source[sizeof(source)];){
    *ptr2 = *ptr1;

    ptr1++;
    ptr2++;
  }

}

int main(void){
  char src[100];
  char dest[100];

  printf("Input a sentence to be copied : ");
  scanf("%[^\n]%*c", src);

  copyString(src, dest);
  
  printf("Original string: %s \n" , src);
  printf("Final copied string: %s \n", dest);

   return(0);
}
