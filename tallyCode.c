#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_NAMELEN 10

//define our struct here
struct person {
	char name[MAX_NAMELEN];
	int rangeMax;
	int rangeMin;
	int pTally;
} person;

//Where the magic happens
int main(int argc, char const *argv[]){

	int numOfTurns = 0;
	int numPlayers = 0;
	int flag = TRUE;	//for tie breaking purposes

	//ask user for input
	printf("\nNumber of players: ");
	scanf("%d", &numPlayers);

	while(numPlayers < 2){
		printf("\nEnter 2 or more players!\n");
		printf("Number of players: ");
		scanf("%d", &numPlayers);
		if(numPlayers > 2)
			break;
	}

	//declare and initialize struct
	struct person players[numPlayers];

	//ask the user how many times this should be done
	printf("Number of turns: ");
	scanf("%d", &numOfTurns);

	while(numOfTurns < numPlayers){
		printf("Enter a value equivalent to the number of players!\n");
		printf("\nNumber of turns: ");
		scanf("%d", &numOfTurns);
		if(numOfTurns >= numPlayers)
			break;
	}

	int x;
	int range = 100/numPlayers;	//define the range
	printf("Players have a range of %d\n\n", range);

	for(x = 0; x < numPlayers; x++){

		char name[MAX_NAMELEN];

		printf("Player %d name: ", x+1);
		scanf("%s", name);
		strcpy(players[x].name, name);

 		int max = (x+1)*range;
		int min = (max+1)-range;

		players[x].rangeMax = max;
		players[x].rangeMin = min;

		players[x].pTally = 0;

		printf("Range: %d - %d\n\n", players[x].rangeMin, players[x].rangeMax);

	}

	//randomize per given iteration
	int num = 0;
	int i;

	printf("Randomizing numbers between 1-100 for %d iterations.\n\n", numOfTurns);
	for(i = 0; i < numOfTurns; i++){

		srand( time(NULL) );
		sleep(1);

		num = rand() % 100 + 1;	//so that its inclusive to 1-100 range
		printf("Random #%d is %d\n", i+1, num);

		//check and tally
		int j;
		for(j=0; j<numPlayers; j++){

			if(num < players[j].rangeMax && num > players[j].rangeMin){
				players[j].pTally++;
				
			}
		}
	}
	sleep(1);
	printf("\n");

	//check if the proceeding element is less than the current
	int k, highest = 0, counter = 0;
	for(k=0; k<numPlayers; k++){

		printf("Player %s has %d tallies\n", players[k].name, players[k].pTally);

		if(players[highest].pTally < players[k].pTally){
			highest = k;
		}
	}

	//check if there are any matching element values
	//if there are, add to the counter
	int j;
	for(j=0; j<numPlayers; j++){
		if(players[highest].pTally == players[j].pTally){
			if(j == highest){
				//do nothing
			}
			else {
				counter++;
			}
		}
	}

	//declare the results either with a winner or a tie
	if(counter > 0){
		printf("\nTIE!\n\n");
		counter = 0; //reset counter
		flag = TRUE;
	}
	else{
		printf("\nPlayer %s wins!\n\n", players[highest].name);
		flag = FALSE;
	}

	if(flag){

		while(flag == TRUE){
			printf("TIE BREAKER\n\n");

			//reset the tallies
			int x;
			for(x=0; x<numPlayers; x++){
				players[x].pTally = 0;
				//printf("Player %s tally value now %d\n", players[x].name, players[x].pTally);
			}

			//randomize per given iteration
			int num = 0;
			int i;

			printf("Randomizing numbers between 1-100 for %d iterations.\n\n", numOfTurns);
			for(i = 0; i < numOfTurns; i++){

				srand( time(NULL) );
				sleep(1);

				num = rand() % 100 + 1;	//so that its inclusive to 1-100 range
				printf("Random #%d is %d\n", i+1, num);

				//check and tally
				int j;
				for(j=0; j<numPlayers; j++){

					if(num < players[j].rangeMax && num > players[j].rangeMin){
						players[j].pTally++;
						
					}
				}
			}
			sleep(1);
			printf("\n");

			//check if the proceeding element is less than the current
			int k, highest = 0, counter = 0;
			for(k=0; k<numPlayers; k++){

				printf("Player %s has %d tallies\n", players[k].name, players[k].pTally);

				if(players[highest].pTally < players[k].pTally){
					highest = k;
				}
			}

			//check if there are any matching element values
			//if there are, add to the counter
			int j;
			for(j=0; j<numPlayers; j++){
				if(players[highest].pTally == players[j].pTally){
					if(j == highest){
						//do nothing
					}
					else {
						counter++;
					}
				}
			}

			//check if there are any matching element values
			//if there are, add to the counter
			int y;
			for(y=0; y<numPlayers; y++){
				if(players[highest].pTally == players[y].pTally){
					if(y == highest){
						//do nothing
					}
					else {
						counter++;
					}
				}
			}

			//declare the results either with a winner or a tie
			if(counter > 0){
				printf("\nTIE!\n\n");
				counter = 0; //reset counter
				flag = TRUE;
			}
			else{
				printf("\nPlayer %s wins!\n\n", players[highest].name);
				break;
			}

		}
	}
	else {
		//do nothing
	}

	return 0;
}//end main