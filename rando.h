#ifndef _rando_h
#define _rando_h 

#include <time.h>
#include <string.h>

enum inclusiveRange{ minNumb = 1, maxNumb = 100}; 

int check_cheat(int argc, char *argv[], int rando)
{
    //Check to see if I have the optional C in the command line. 
    //If I don't have 2 and have > 2 or < 2 continue without Cheat. 
    //Likewise if have two put don't have 'C' continue without Cheat. 
    if (argc == 2){
        char *argString = argv[1]; 
        if (strcmp(argString, "C")==0){
            return 1;
        } 
    }
    return 0; 
}

int generate_rand(void)
{
    time_t t;
	time(&t);

	// seed the random number generator
	srand(t);
    //Generate a number from 1 to 100, inclusive
    //Formula sourced from: c-faq.com/lib/randrange.html
    int rando = rand() % ((maxNumb - minNumb)+1) + minNumb;
	return rando;
}


#endif 
