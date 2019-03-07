#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "support.c"
#include "linked_list.c"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  not_empty   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  not_full    = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
char letter = 'a'; //the starting letter
#define MAX 10//buffer size

LINKED_LIST *head;

void *put();
void *fetch();

int main(){

head = Node_create();

pthread_t thread1;
pthread_t thread2;

//: Creates the thread
if (pthread_create(&thread1, NULL, put, "arg 1") != 0) {
  perror("pthread_create() error");
  exit(1);
}

//: Creates the thread
if (pthread_create(&thread1, NULL, fetch, "arg 1") != 0) {
 perror("pthread_create() error");
 exit(1);
}

   while(1){
     sleep(1000);
     printf("Main is executing \n");
   }
}

char nextChar(){
  if((int)letter <= (int)'z' )
    return letter++;
  else
    return letter = 'a';
}

void *put(){
    while(1){

      if(Node_size(head) >= MAX){
        pthread_cond_wait(&not_full, &lock);
      }else{
        Node_add(head , nextChar());
        printf("Buffer store \n");
        pthread_cond_signal(&not_empty);
      }

      //pthread_cond_signal(&not_empty);
      //pthread_cond_wait(&not_full, &lock);

      sleep(1000);
    }
}

void *fetch(){
    while(1){

      if(Node_size(head) == 0){
        pthread_cond_wait(&not_empty, &lock);
      }else{
        char c = head->data;
        if(head->next != NULL){
          head = head->next;
        }else{
          pthread_cond_wait(&not_empty, &lock);
        }
        printf("Buffer output : %c \n" , c);
        pthread_cond_signal(&not_full);
      }

      sleep(1000);
    }
}
