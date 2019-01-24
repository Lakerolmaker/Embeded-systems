
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_GUESS 10

int number_of_tries = 0;

int tries_left(){
    return MAX_GUESS - number_of_tries;
}

int random_number(int min_num, int max_num){
    return(rand() % ((max_num ) - min_num) + 1) + min_num;
}

int keepPlaying(){
    while(1){
        printf("Want to keep playing (y/n) ? \n");

        char guess[50];
        scanf("%s", guess);

        int i;
        for (i = 0; guess[i] != '\0' ; i++) {
            if(guess[i] == 'y'){
                return 1;
            }else if(guess[i] == 'n'){
                return 0;
            }
        }
    }
}

int main() {

    int guess = 0;
    int number = random_number(0,100);
    printf("Hi, Guess the number! It is between 0 and 100: ");
    scanf("%d", &guess);

    while(1) {

    if (guess < number && tries_left() != 0){
        number_of_tries++;
        printf("Too low! \n");
        printf("You have %d tries left: ", tries_left());
        scanf("%d", &guess);

    }else if (guess > number && MAX_GUESS != 0) {
        number_of_tries++;
        printf("Too high! \n");
        printf("You have %d tries left: ", tries_left());
        scanf("%d", &guess);

    }else if (MAX_GUESS == 0) {
        printf("You ran out of tries");
        if(keepPlaying() == 0){
                break;
        }

    }else {
        printf("You guessed %d, that´s the number! \n", number);
        if(keepPlaying() == 1){
            number_of_tries = 0;
        }else{
            break;
        }
    }

    }

}
