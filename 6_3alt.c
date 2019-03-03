#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(var,pos) (var >> pos) & 1
#define EXIT_STATE end
#define ENTRY_STATE entry
#define statusPORT 0x0B00
#define controlPORT 0x0B00


*portopen = B10000000;
*portclose = B01000000;

int bits;
//close doors
int entry_state(void);
//read state
int read_state(void);
//open state
int open_state(void);

int exit_state(void);

int (* state[])(void) = { entry_state, read_state, open_state, exit_state};
enum state_codes { entry, read, open, end};

enum ret_codes { ok, fail, repeat};
struct transition {
    enum state_codes src_state;
    enum ret_codes   ret_code;
    enum state_codes dst_state;
};
struct transition state_transitions[] = {
    {entry, ok,     read},
    {entry, fail,   end},
    {read,   ok,     open},
    {read,   fail,   end},
    {read,   repeat, read},
    {open,   ok,     end},
    {open,   fail,   end},
    {open,   repeat, read}};



void setBit(int *bits, int index, int b){
    if(b)
        BIT_SET(*bits, index);
    else
        BIT_CLEAR(*bits, index);
}


entry_state(void) {
  while (statusPORT != "B00100000") {
  setBit(&PORT, 7, BIT_CHECK(bits ,1);)
}

}

read_state(void) {
    do{   setBit(&PORT, 8, BIT_CHECK(bits ,1);) }
  while (statusPORT == "B00000001" || statusPORT == "B00000010" )


}

int main (void)
{
  enum state_codes cur_state = ENTRY_STATE;
     enum ret_codes rc;
     int (* state_fun)(void);

     for (;;) {
         state_fun = state[cur_state];
         rc = state_fun();
         if (EXIT_STATE == cur_state)
             break;
             //lookup has to be implemented
         cur_state = lookup_transitions(cur_state, rc);
     }

 return EXIT_SUCCESS;



}
