// ====================================
// File name: exerc_3_2.c (or cpp)
// Date: 2019-02-4
// Group Number: 21
// Members That contributed:
// Jacob Olsson
// Victor Roman
// Members not present at the demonstration :
// Xxxxxxx
// Demonstration code: [<Ass code 29514> ]
// ======================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int search_number( int number, int *tab , int size){
  int *ptr = tab;
  int i = 0;
  for(; ptr < &tab[size];){
    if(*ptr == number){
      return i;
    }

    i++;
    ptr++;
  }

  return -1;
};

void swap(int *int1 , int *int2){
  int tmp = *int1;
    *int1 = *int2;
    *int2 = tmp;
}

void selectionSort(int *array , int size){
  int *ptr1 = array;
  for(;ptr1 < &array[size]; ptr1++){
    int *ptr2 = ptr1;
    for(;ptr2 < &array[size];ptr2++){
      if(*ptr1 > *ptr2){
        swap(ptr1 , ptr2);
      }
    }
  }
}

void bubbleSort(int *array , int size){
  int *reference = array;
  for(;reference < &array[size - 1]; reference++){
    int *ptr1 = array;
    int *ptr2 = array + 1;
    for(;ptr2 < &array[size];){
      if(*ptr1 > *ptr2){
        swap(ptr1 , ptr2);
      }
      ptr1++;
      ptr2++;
    }
  }
}

void printArray(int *array, int size){
  printf("Array : ");
  int *ptr = array;
  for(;ptr < &array[size]; ptr++){
    printf("%d ", *ptr);
  }
  printf("\n");
}

int main(int argc, char *argv[]){

int test [] = { 1,2,34,5,67,3,23,12,13,10};

int search_for = 13;
int index = search_number(search_for ,test , NELEMS(test));

printArray(test, NELEMS(test));
printf("First instance of number %d is index %d \n" , search_for , index );
bubbleSort(test, NELEMS(test));
printArray(test, NELEMS(test));


}
