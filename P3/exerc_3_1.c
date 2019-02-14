#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum DIRECTION {N,E,S,W};
enum boolean {true, false};

//maximums
#define WIDTH 99
#define HEIGHT 99

//constructor for robot
typedef struct {
int x;
  int y;
  enum DIRECTION dir;
} ROBOT;

//turn function, switch case based on current position
void turn(ROBOT *rob){
  switch(rob->dir){
    case N:
      rob->dir = E;
    break;
    case E:
      rob->dir = S;
    break;
    case S:
      rob->dir = W;
    break;
    case W:
      rob->dir = N;
    break;
  }
}


//move function, move one step depending on position, constrained
void move(ROBOT *rob){
  int x = rob->x;
  int y = rob->y;


  switch(rob->dir){
    case N:
      if(y > 0)
        rob->y--;
    break;
    case S:
      if(y < HEIGHT)
        rob->y++;
    break;
    case W:
      if(x > 0)
        rob->x--;
    break;
    case E:
      if(x < WIDTH)
        rob->x++;
    break;
  }


}

int main(int argc, char *argv[]){

  char directions[4] = {'N','E','S','W'};
  //initialize robot, allocate memory for it
  ROBOT *robot = (ROBOT*)malloc(sizeof(ROBOT));
  robot->dir = N;
  robot->x = 0;
  robot->y = 0;

  //initialize "program", take input in loop
  char command[255];
  printf("ROBOT simulator V1.0 \n");
  LOOP:;
  int x = robot->x;
  int y = robot->y;
  char dir = directions[robot->dir];
  printf("Robots position : X%d , Y%d , Facing %c \n",x ,y, dir);
  printf("Input command for robot: (m/t) , press (Q to exit): ");
  scanf("%[^\n]%*c", command);
//execute command
  int i;
  for(i = 0; i < strlen(command); i++){
      if(command[i] == 'm')
        move(robot);
      else if(command[i] == 't')
        turn(robot);
      else if(command[i] == 'q' || command[i] == 'Q')
        goto END;
  }
  goto LOOP;
  END:;


}
