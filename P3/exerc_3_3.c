// ====================================
// File name: exerc_3_3.c (or cpp)
// Date: 2019-02-4
// Group Number: 21
// Members That contributed:
// Jacob Olsson
// Victor Roman
// Members not present at the demonstration :
// Xxxxxxx
// Demonstration code: [<Ass code 29471> ]
// ======================================
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 20

// ##### Typdeklaretioner ####
typedef struct q{
        int data;
        struct q *prev;
        struct q *next;
} REGTYPE;


REGTYPE* random_list(){
    int nr, i=0;
    REGTYPE *top, *old, *item;
    top = (REGTYPE*) malloc(sizeof(REGTYPE));
    nr = rand() % 100;
    top->data=nr;
    top->prev=NULL;
    top->next=NULL;
    item = top;
    i++;
    while(i<MAX){
                 old=item;
                 item = (REGTYPE*) malloc(sizeof(REGTYPE));
                 nr=rand()%100;
                 item->data=nr;
                 item->prev=old;
                 item->next=NULL;
                 old->next=item;
                 i++;
    }
    return(top);
}

REGTYPE* add_to_first(REGTYPE *head ,int number){

  REGTYPE *node;
  node = (REGTYPE*) malloc(sizeof(REGTYPE));
  node->data = number;
  node->next= head;
  head->prev = node;
  return node;

}

void printNode(REGTYPE *node){
  REGTYPE *head = node;
  int i = 0;
  while( head != NULL){
         printf("Node nr %d : %d \n" , i++, head->data);
         head = head->next;
  }
}


int main(int argc, char *argv[]){
    int nr = 0;
    REGTYPE *act_post, *temp, *head = NULL;
    srand(time(0));
    printf("Original list : \n");
    head = random_list();
    printNode(head);
    printf("After adding 100 to the top : \n");
    head = add_to_first(head , 100);
    printNode(head);


  //: return as an exit protocol
  return 0;
}
