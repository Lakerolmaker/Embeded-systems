
#include <stdlib.h>
#include <stdio.h>

#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(var,pos) (var >> pos) & 1
#define EXIT_STATE end
#define ENTRY_STATE entry
#define statusPORT 0x0B00
#define controlPORT 0x0B00
int bits;
void setBit(int *bits, int index, int b){
    if(b)
        BIT_SET(*bits, index);
    else
        BIT_CLEAR(*bits, index);
}

enum states {
	START,
	LOOP,
	END,
} state;

enum events {
	START_LOOPING,
	READ,
	OPEN,
	STOP_LOOPING,
};

void step_state(enum events event) {
	int flag=0;

	switch(state) {
	case START:
		switch(event) {
		case START_LOOPING:
		entry_state();
			state = LOOP;
			break;
		default:
			exit(1);
			break;
		}
		break;

	case LOOP:
		switch(event) {
		case READ:
 		read_state();
			break;

		case OPEN:
			open_state();
			break;

		case STOP_LOOPING:
			state = END;
			break;

		default:
			exit(1);
			break;
		}
		break;
	case END:
		exit(1);
		break;
	}
}

	entry_state(void) {
//	  while (statusPORT != "B00100000") {
//	  setBit(statusPORT, 7, BIT_CHECK(bits ,1));
//		printf("start\n");
//	}
	printf("start\n");
	}

	read_state(void) {
		printf("wait for button!\n"); //keep reading
		 		printf("button pressed!\n"); //detect button


	}

	open_state() {
			printf("opening!\n");
			printf("waiting!\n");
			printf("closing!\n");
	}

int main(void) {
	step_state(START_LOOPING);
	step_state(READ);
  step_state(OPEN);
	return 0;
}
