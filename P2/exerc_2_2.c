#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100


int random_number(int min_num, int max_num){
    return(rand() % ((max_num ) - min_num) + 1) + min_num;
}

int byteSize(const int *input[]){
  return sizeof(input);
}


int main(void){
  srand(time(0));

  int array[100];

  int i;
  for(i = 0; i < MAX; i++){
    array[i] = random_number(1,99);
  }

  printf("The value of the label array( address ) is: %p \n", &array);
  printf("First integer in the array is ( array[0] ) is : %d \n", array[0]);
  printf("The size of an integer (number of bytes) is : %ld \n", sizeof(array));
  printf("The size of the whole array is : %lu \n", sizeof(array) / sizeof(array[0]));

}
