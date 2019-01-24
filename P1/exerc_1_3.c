//: Encryption , moving the character 13 steps forward

#include <stdio.h>
#include <stdlib.h>

char table1[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char table2[26] = {'n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m'};

void print(char* sentence){
    int a;
    for (a = 0; a < sizeof(sentence); a++){
        printf("%c",  sentence[a]);
    }
    printf("\n");
}

int getIndex(char letter){
    int i;
    for(i = 0; i < sizeof(table1); i++){
        if(table1[i] == letter){
            return i;
        }
    }
    return 1000;
}

char getTrans(int i){
    return table2[i];
}

char toLowerCase(char letter) {
    return letter + 32;
}

char toUpperCase(char letter) {
    return letter - 32;
}

int isLowerCase(char letter){
    if (letter >= 'a' && letter <= 'z'){
        return 1;
    }else{
        return 0;
    }
}

int isUpperCase(char letter){
    if (letter >= 'A' && letter <= 'Z'){
        return 1;
    }else{
        return 0;
    }
}

int isInAlphabet(char letter){
    if(isUpperCase(letter) == 1 || isLowerCase(letter) == 1){
        return 1;
    }else{
        return 0;
    }
}

char original_word[100];
char new_word[100];
char encrypted;

int main(void) {


    printf("Type your word: ");
    scanf("%[^\n]%*c", original_word);

    int i;
    for (i = 0; original_word[i] != '\0' ; i++) {
            //: checks if the word is in the alhpabet
            if(isInAlphabet(original_word[i])){
                char letter = original_word[i];
                if(isUpperCase(letter) == 1){
                    letter = toLowerCase(letter);
                }
                encrypted = getTrans(getIndex(letter));
                if (isUpperCase(original_word[i]) == 1) {
                    encrypted = toUpperCase(encrypted);
                }
                new_word[i] = encrypted;
            }
    }
    print(new_word);
}
