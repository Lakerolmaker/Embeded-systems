#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>




double get_time_ms(){
 struct timeval t;
 gettimeofday(&t, NULL);
 return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

double program_time = get_time_ms();


// ----- Tread functions –
//--------------------------------------------
void time_count() {
  while (program_time < 50){

  }
}

void read_inport(){
  while (program_time<50){
  }
}

void *thread(void *arg) {
  char *ret;
  printf("thread() entered with argument '%s'\n", arg);
  if ((ret = (char*) malloc(20)) == NULL) {
    perror("malloc() error");
    exit(2);
  }
  strcpy(ret, "This is a test");
  pthread_exit(ret);
}


int main(){

    pthread_t thid;
    void *ret;

    if (pthread_create(&thid, NULL, thread, "thread 1") != 0) {
      perror("pthread_create() error");
      exit(1);
    }

    if (pthread_join(thid, &ret) != 0) {
      perror("pthread_create() error");
      exit(3);
    }

    printf("thread exited with '%s'\n", ret);

 return 0;
}
// --- End of main thread ------
