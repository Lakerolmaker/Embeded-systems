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

char toUpperCase(char letter) {
    return letter-32;
}

int isLower(char letter){
    if (letter >= 'A' && letter <= 'Z'){
        return 0;
    }else{
        return 1;
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
            int index = getIndex(original_word[i]);
            if(index != 1000){
                encrypted = getTrans(index);
                if (isLower(original_word[i]) == 1) {
                    new_word[i] = encrypted;
                } else {
                    new_word[i] = toUpperCase(encrypted);
                }
            }
    }
    print(new_word);
}
