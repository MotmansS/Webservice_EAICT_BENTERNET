/*
Blackjack: Code verwezenlijkt door Smolders Xander en Motmans Sam, 1PBEAI-C
Gebruik gemaakt van template gegeven door docent: Gilissen Koen, Vreys Frederik.
*/
#include "blackjack.h"
#include "zmq.h"
#
char playerHand[9] = {"GGGGGGGGG"};
char computerHand[9] = {"GGGGGGGGG"};

int main(void)
{   char *computerhand;
    char *playerhand;
    printf("\033[0;32m"); //Groene console
    srand(time(NULL));	  //Kaarten randomizen
    printIntro();
    char concattothis [200] = "BlackJackService>player>";
    char name[40];
    char doorgaan[20];
      printf("we got1\n");
    printf("Enter name:\n ");

    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH);
    void *reciever = zmq_socket (context, ZMQ_SUB);
     printf("we got1");
    zmq_connect (sender, "tcp://benternet.backup.pxl-ea-ict.be:24041");
    zmq_connect (reciever, "tcp://benternet.backup.pxl-ea-ict.be:24042");
    printf("we got2");
    int request_nbr;
    char buffer [5000];
     printf("we got3");
    zmq_setsockopt (reciever, ZMQ_SUBSCRIBE, strcat(strcat(concattothis,"barry"),">"), strlen (strcat(strcat(concattothis,"barry"),">")));
    zmq_send(sender,strcat(strcat(concattothis,"barry"),">"),strlen(strcat(strcat(concattothis,"barry"),">")),0);
    zmq_recv(reciever,buffer,5000,0);
    

    // loop through the string to extract all other tokens
	printf("we recieved a name");


   
    
    
	while(arrayToScore(playerHand) < 21 && arrayToScore(computerhand) < 21)
	{
		puts("Do you want to continue y/n?: ");
		fgets(doorgaan,20,stdin);
		strtok(doorgaan, "\n");
		char concattothis2[200] = "BlackJackService>Client>";
		zmq_send(sender,strcat(strcat(concattothis,doorgaan),">"),strlen(strcat(strcat(concattothis,doorgaan),">")),0);
		for(int i = 0; i < 20;i++)
		{
			zmq_recv(reciever,buffer,5000,0);
			if (strstr(buffer,"PlayerHand") != NULL){
				playerhand = strrchr(buffer, '>');
				if (playerHand != NULL) {
		   		 	
		   		 	break;
		   		 	
				 }
			}
    
		}
		for(int i = 0; i < 20; i++)
		{
			zmq_recv(reciever,buffer,5000,0);
			if (strstr(buffer,"ComputerHand") != NULL){
				computerhand  = strrchr(buffer, '>');
				if (computerhand != NULL) {
		   		 	
		   		 	break;
		   		 	
				 }
			}
    
		}
		
		visualize(9,playerHand,computerhand);
		
		/*stiekeme easter egg*/
		 if(strcmp("Hi",doorgaan) == 0 || strcmp("Hello",doorgaan) == 0) { playEasterEgg(); }
	}
	checkVictory(playerHand, computerhand);
    zmq_close (sender);
    zmq_close (reciever);
    zmq_ctx_destroy (context);
}
