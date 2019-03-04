#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;
int true = 1, false = 0;

double get_time_ms(){
 struct timeval t;
 gettimeofday(&t, NULL);
 return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

int program_time;

double previousMillis;
int timeHasPassed(int milisecond){
  if (get_time_ms() - previousMillis >= milisecond) {
    previousMillis = get_time_ms();
    return 1;
  }else{
    return 0;
  }
}

void sleep(int milisecond){
	 double stop_time = get_time_ms() + milisecond;
   for(;;){
     if(get_time_ms() >= stop_time){
       return;
     }
   }
}

void *read_inport(void *arg){
  int previous_num;
  while (program_time<50){
    if((program_time != previous_num) && (program_time % 5 == 0)){
      previous_num = program_time;
      printf("Reading inport now \n");
    }
  }
  pthread_exit("job's done");
}

void *time_count(void *arg) {

  while(program_time < 50){
    if(timeHasPassed(1000)){
        program_time++;
    }
  }

  pthread_exit("job's done");
}


int main(){

    previousMillis  = get_time_ms();

    pthread_t thread1;
    pthread_t thread2;
    void *ret;

    //: Creates the thread
    if (pthread_create(&thread1, NULL, time_count, "arg 1") != 0) {
      perror("pthread_create() error");
      exit(1);
    }

    //: Creates the thread
    if (pthread_create(&thread2, NULL, read_inport, "arg 2") != 0) {
      perror("pthread_create() error");
      exit(1);
    }

    int previous_num;
    while (program_time<50){
      if(program_time != previous_num){
        printf("Program time %d \n" , program_time);
        previous_num = program_time;
      }
    }


    exit(1);
}
// --- End of main thread ------
