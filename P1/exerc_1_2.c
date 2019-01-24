// Write a program that reads in a sentence of MAX characters and counts the number of words in it.
// The number of words should then be printed out on the console window.//

#include <stdio.h>
#include <stdlib.h>

int main(void){
        char* string;
        int number_of_words;
        printf("Input a sentence: ");
        scanf("%[^\n]s", string);
        int a;
        for(a = 0; string[a] != '\0'; a++){
            if(a !=0){
                if((string[a] == ' '  && string[a - 1] != ' ' )){
                    number_of_words++;
                }
            }
        }

        if(string[a - 1] != ' '){
            number_of_words++;
        }

    printf("number of words in sentence : %d \n" , number_of_words);

}
