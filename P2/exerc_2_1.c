#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(char *destination, char *source){
  int i;
  for(i = 0; i < strlen(source); i++){
    destination[i] = source[i];
  }
}

int main(void){
  char src[100];
  char dest[100];

  scanf("%[^\n]%*c", src);
  copyString(dest, src);

  printf("Final copied string: %s \n", dest);

   return(0);
}
