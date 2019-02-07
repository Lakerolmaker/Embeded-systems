// Passed 7579
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readPersnr( char *person){
    printf("Input person number: ");
    scanf("%[^\n]%*c", person);
}

//: Algoritm for the lohm algortim , found online
int controlDigit( const char * persnr ){
    int nDigits = strlen(persnr);
    int nSum = 0, isSecond = 0;

    for (int i = nDigits - 1; i >= 0; i--) {

        int d = persnr[i] - '0';

        if (isSecond == 1)
            d = d * 2;

        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}

int main(int argc, char *argv[]){

    char personnr[20];

    readPersnr(personnr);

    printf("Person number is correct : %d \n" , controlDigit(personnr));

}
