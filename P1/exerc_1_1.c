
// Write a program that reads in an integer number between 1 and 5 from the keyboard and prints out
// one of existing five sentences on the console depending on what number was entered.
// The program continues to ask for a new number and exits if number isn´t in the interval 1 to 5.


#include <stdio.h>
#include <stdlib.h>
int main(void){
    while(1){
        int a;
        printf("Input a number: ");
        scanf("%d", &a);
        switch (a) {
          case 1:
            printf("option 1\n");
            break;
          case 2:
            printf("option 2\n");
            break;
          case 3:
            printf("option 3\n");
            break;
          case 4:
            printf("option 4\n");
            break;
          case 5:
            printf("option 5\n");
            break;
        default:
            return 1;
        break;
                }
    }
}
