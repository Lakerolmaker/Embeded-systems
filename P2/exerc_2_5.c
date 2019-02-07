// passed 7511
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MAXNUMBER 20

int random_number(int min_num, int max_num){
    return(rand() % ((max_num ) - min_num)) + min_num;
}

void create_random( int *tab ){
    int i;
    for(i = 0; i < MAX; i++){
        tab[i] = random_number(0 , MAXNUMBER);
    }
}

//for each number in the table, add a counter correspondent to that number in the table
void count_frequency(int *tab, int *freq){
    int i;
    int z;
    for(i = 0; i < MAXNUMBER; i++){
        for(z = 0; z < MAX; z++){
            if(i == tab[z]){
                freq[tab[i]]++;
            }
        }
    }
}
//by passing frequency, depending on the count, draw that amount of Xs for each number
void draw_histogram(int *freq ){
    int number = 0;
    int i;
    for(i = 0; i < MAXNUMBER; i++){
        printf("%d" , i);
        int z = 0;
        for(; z < freq[i]; z++){
            printf("X");
            number++;
        }
        printf("\n");
    }
    printf("Number of numbers : %d \n" , number);
}

int main (void){
srand(time(0));
int table[MAX], n ;
int frequency[MAXNUMBER];

create_random(table);
count_frequency(table ,frequency);
draw_histogram(frequency);

}
