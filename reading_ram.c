#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

  char  *ptr;
  while(1){
    if(*ptr != 0)
      printf("The value of ptr is : %s \n", ptr  );
    ptr++;
  }

}
