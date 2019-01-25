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
void count_frequency(int *tab, int *freq ){
    int i;
    int z;
    for(i = 0; i < MAX; i++){
        for(z = 0; z < MAX; z++){
            if(tab[i] == tab[z]){
                freq[tab[i]]++;
            }
        }
    }
}

void draw_histogram(int *freq ){
    int i;
    for(i = 0; i < MAXNUMBER + 1; i++){
        printf("%d " , i);
        int z;
        for(z = 0; z < freq[i]; z++){
            printf("X");
        }
        printf("\n");
    }
}

int main ( void){
srand(time(0));
int table[MAX], n ;
int frequency[MAXNUMBER];

create_random(table);
count_frequency(table ,frequency);
draw_histogram(frequency);

}
