#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isSame(char *str1 , char *str2){
  int i;
  for(i = 1; i < strlen(str1); i++){
    if(str1[i] != str2[i]){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]){

  if(argc == 3){
      printf("The arguments are the same : %d \n" , isSame(argv[1], argv[2]));
      printf("void : %c \n" , argv[1][100] );

  }else{
    printf("Did not include two strings as argument");
  }

}
