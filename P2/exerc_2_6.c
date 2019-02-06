#include<stdlib.h>
#include<stdio.h>
#include<string.h>



void initQue (int *list, int max) {
    int i = 0;
    for (; i<list[max]; i++) {
        list[i] = -1;
    }

}

void input( int *list, int number, int max) {
    int count=0;
    int i = 0;
    for(; i<max; i++){
        if (list[i] != -1){
          count++;
        }else if (count == max) {
            printf("im full");
        }
        else{break;}
    }

    list[count] = number;
}

void output(int *list, int max) {
    int count = 0;
    int i = 0;
    int j = 0;
    for (; i < max; i++) {
        if (list[i] != -1) { count++; }
    }
    if (count != 0) {
        for (; j<count; j++) {
        printf("%d", list[j]);
        }
    }else {
        printf("izempty");
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
int main() {

int que[5];

initQue(que, 5);
printArray(que, 5);
input(que, 2, 5);
printArray(que, 5);
output(que, 5);

}
