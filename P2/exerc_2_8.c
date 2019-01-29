/*
 *  File    : nim.c
 *  Program : Nim game
 *  Author  : Jacob
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile){

  printf("Enter the amount of couns you would like to take. range (1-3): ");
  int input = 0;
  scanf("%d", &input);
  return input;

}

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player ){
  if(player == 1){
    printf("You win ! \n");
  }else{
    printf("The cumputer wins ! \n");
  }

}

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again(){
    printf("Do you wish to play again? (Y/N): ");
    Loop:;
    char input;

    scanf("%c", &input);

    if(input == 'n' || input == 'N'){
      return 0;
    }else if(input == 'y' || input == 'Y'){
      return 1;
    }else{
      goto Loop;
    }
}

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */

 //: returns a random number
 int random_number(int min_num, int max_num){
     return(rand() % ((max_num ) - min_num) + 1) + min_num;
 }

int computer_choice(int pile){
  if(pile == 4){
    return 3;
  }
  return random_number(1,3);
}

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player ){
  player = !player;
  return player;
}

int main()
{
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;		/* Number of coins taken */

  srand( time(0) );		/* Setup random */

  printf("Welcome to NIM by Jacob");

  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;

  /*
   *  Program main loop
   */
  while( true ) {

    printf("There are %d coins in the pile \n", pile );

    if( player == HUMAN ){
      n_coins = human_choice(pile);
    }else{
      n_coins = computer_choice(pile);
      printf("The computer took %d coins\n", n_coins);
    }

    pile -= n_coins;
    player = toggle( player );

    if( pile <= 1 ){
      write_winner( player );
      if(play_again()){
          player = HUMAN;
          pile = MAX_COINS;
      }else{
          break;
      }

    }
  }
  /*
   * end main loop
   */

  printf("Game has ended, thanks for playing\n");

  return 0;
}
