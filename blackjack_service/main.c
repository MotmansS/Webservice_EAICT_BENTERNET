/*
Blackjack: Code verwezenlijkt door Smolders Xander en Motmans Sam, 1PBEAI-C
Gebruik gemaakt van template gegeven door docent: Gilissen Koen, Vreys Frederik.
*/
#include "blackjack.h"

char playerHand[9] = {"GGGGGGGGG"};
char computerHand[9] = {"GGGGGGGGG"};

int main(void)
{
	printf("\033[0;32m"); //Groene console
    srand(time(NULL));	  //Kaarten randomizen
    printIntro();
    
    char doorgaan[20];
	while(arrayToScore(playerHand) < 21 && arrayToScore(computerHand) < 21)
	{
		puts("Do you want to continue y/n?: ");
		fgets(doorgaan,20,stdin);
		strtok(doorgaan, "\n");
		if(strcmp("y",doorgaan) == 0 || strcmp("Y",doorgaan) == 0) 
		{ 
			//CPU takes turn and then player (hopefully does)
			if(arrayToScore(computerHand)< 16) { printf("House increases score\n"); fillArrayRandom(computerHand,PLAYER_cpu); }
			else { printf("House holds\n"); }
			fillArrayRandom(playerHand,PLAYER_user);
			visualize(9, playerHand, computerHand);
		}
		/* Easy wins voorkomen*/
		else if(strcmp("n",doorgaan) == 0 || strcmp("N",doorgaan) == 0) 
		{
			for (size_t i = 0; i < strlen(computerHand); i++) 
			{
				if(arrayToScore(computerHand)< 16) { fillArrayRandom(computerHand,PLAYER_cpu); }
				else { break; }
			}
			visualize(9, playerHand, computerHand);
			break;
		}
		/*stiekeme easter egg*/
		else if(strcmp("Hi",doorgaan) == 0 || strcmp("Hello",doorgaan) == 0) { playEasterEgg(); }
	}
	checkVictory(playerHand, computerHand);
}
