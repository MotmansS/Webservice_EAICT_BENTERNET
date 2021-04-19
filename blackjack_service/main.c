/*
Blackjack: Code verwezenlijkt door Smolders Xander en Motmans Sam, 1PBEAI-C
Gebruik gemaakt van template gegeven door docent: Gilissen Koen, Vreys Frederik.
*/
#include "blackjack.h"

char playerHand[9] = '/0';
char computerHand[9] = '/0';

int main(void)
{
	//magic server stuff
	void *context = zmq_ctx_new();
	void *responder = zmq_socket(context, ZMQ_REP);
	int rc = zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);

	zmq_send(responder,"\033[0;32m",8,0); //Groene console
	srand(time(NULL));	  //Kaarten randomizen
	printIntro(responder);

	while (1)
	{
		char doorgaan[20];
		while (arrayToScore(playerHand) < 21 && arrayToScore(computerHand) < 21)
		{
			zmq_send("Do you want to continue y/n?: ",31,0);
			zmq_recv(responder,doorgaan, 1,0 );
			strtok(doorgaan, "\n");
			if (strcmp("y", doorgaan) == 0 || strcmp("Y", doorgaan) == 0)
			{
				//CPU takes turn and then player (hopefully does)
				if (arrayToScore(computerHand) < 16)
				{
					printf("House increases score\n");
					fillArrayRandom(computerHand, PLAYER_cpu);
				}
				else
				{
					printf("House holds\n");
				}
				fillArrayRandom(playerHand, PLAYER_user);
				visualize(9, playerHand, computerHand,responder);
			}
			/* Easy wins voorkomen*/
			else if (strcmp("n", doorgaan) == 0 || strcmp("N", doorgaan) == 0)
			{
				for (size_t i = 0; i < strlen(computerHand); i++)
				{
					if (arrayToScore(computerHand) < 16)
					{
						fillArrayRandom(computerHand, PLAYER_cpu);
					}
					else
					{
						break;
					}
				}
				visualize(9, playerHand, computerHand,responder);
				break;
			}
			/*stiekeme easter egg*/
			else if (strcmp("Hi", doorgaan) == 0 || strcmp("Hello", doorgaan) == 0)
			{
				playEasterEgg(responder);
			}
		}
		checkVictory(playerHand, computerHand,responder);
	}
}
