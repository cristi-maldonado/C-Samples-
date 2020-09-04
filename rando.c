#include <stdio.h>
#include <stdlib.h>
#include "rando.h"

int main(int argc, char *argv[])
{
	int rando = generate_rand();
	//return 1 for C option invoked. Give user Cheat number. 
	int cheat = check_cheat(argc, argv, rando); 
	int userGuess; 
	int valid = 0; 
	int invalid = 0; 

	if (cheat == 1){
			printf("Guess a number between 1 and 100. (psst it is %d).\n", rando); 
		}
		else{
			printf("Guess a number between 1 and 100.\n"); 
		}
	printf("Try to guess my number:\t"); 

	do{
		
		if (scanf("%d", &userGuess) == 1){
			if(userGuess > maxNumb || userGuess < minNumb){
				printf("This is not a valid guess. Please try again:\t"); 
				invalid++; 
			}
			else if(rando < userGuess){
				printf("%d is too high - please guess again:\t", userGuess); 
				valid++; 
			}
			else if (rando > userGuess){
				printf("%d is too low - please guess again:\t", userGuess); 
				valid++; 
			}
			else if (rando == userGuess){
				valid++; 
				printf("%d is correct! You guessed my number in %d valid guess(es) and %d invalid guess(es).\n", userGuess, valid, invalid); 
			}
			
		}else{
			//Break out of the program if the user doesn't input
			printf("This is not a valid guess. Integers only >: /\n"); 
			break;
		}

	}while(userGuess != rando); 

}





	/*time_t t;
	time(&t);

	// seed the random number generator
	srand(t);
	// generate a random number between 0-10, not including 10
  int rando = rand() % 25;
	printf("%d\n", rando);
	
	printf("%d\n", generate_rand());*/