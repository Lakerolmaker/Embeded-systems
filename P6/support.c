#include <sys/time.h>


#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;
int true = 1, false = 0;


#define BOOL(x) (!(!(x)))

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) BOOL((a) & (1L << (b)))


int random_number(int min_num, int max_num){
    return(rand() % ((max_num ) - min_num) + 1) + min_num;
}

double get_time_ms(){
 struct timeval t;
 gettimeofday(&t, NULL);
 return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

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
