#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main() {
   

        char input[255];
        printf("insert palindrome");
        scanf("%s", &input);
        char flipped[255];
        int end = strlen(input) - 1;
        int middle = strlen(input)/2;
        int i = 0;

        for (i; i<middle; i++ ) {
            if (input[i] != input[end])
            {printf("woopsie"); break;}
            end--;
        }
        //once you reach the middle
        if (i == middle)
        { printf("yay");}
    }

