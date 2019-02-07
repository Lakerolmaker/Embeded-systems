// passed 7525

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main() {

      //ask for palindrome
        char input[255];
        printf("insert palindrome: ");
        scanf("%s", &input);
        char flipped[255];
        int end = strlen(input) - 1;
        int middle = strlen(input)/2;
        int i = 0;
      //check if its the same until the middle is reached (abba, check if ab and ba flipped is same)
        for (i; i<middle; i++ ) {
            if (input[i] != input[end])
            {printf("It´s not a palindrome \n"); break;}
            end--;
        }
        //once you reach the middle
        if (i == middle)
        { printf("It´s a palindrome");}
    }
