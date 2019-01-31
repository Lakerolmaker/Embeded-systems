#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


int search_number( int number, int *tab , int size){
  int *ptr = tab;
  int i = 0;
  for(; ptr < &tab[size];){
    printf("number at %d is %d \n" , i , *ptr);
    if(*ptr == number){
      return i;
    }

    i++;
    ptr++;
  }

  return -1;
};

int main(int argc, char *argv[]){

int test [] = { 1,2,34,5,67,3,23,12,13,10};

int search_for = 13;
int index = search_number(search_for ,test , NELEMS(test));

printf("First instance of number %d is index %d \n" , search_for , index );


}
