/*
Blackjack: Code verwezenlijkt door Smolders Xander en Motmans Sam, 1PBEAI-C
Gebruik gemaakt van template gegeven door docent: Gilissen Koen, Vreys Frederik.
*/
#include "blackjack.h"
#include "zmq.h"
#include <assert.h>
#include <unistd.h>
char playerHand[9] = {"GGGGGGGGG"};
char computerHand[9] = {"GGGGGGGGG"};




    

int main(void)
{   
    char *computerhand;
    char *playerhand;
    
    zmq_msg_t message;
    zmq_msg_init (&message);
    
    printf("\033[0;32m"); //Groene console
    srand(time(NULL));	  //Kaarten randomizen
    printIntro();
    
    char RecieveConcat [] = "BlackJackService>Player>";
    char SendConcat[] = "BlackJackService>Client>";
    char name[40];
    char doorgaan[10];
    char buffer [5001];
    
    printf("Enter name:\n ");
    scanf("%s",name);
    
    strcat(SendConcat,name);
    
    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH);
    void *reciever = zmq_socket (context, ZMQ_SUB);
    
    strcat(RecieveConcat,name);
    zmq_connect (sender, "tcp://benternet.backup.pxl-ea-ict.be:24041");
    zmq_connect (reciever, "tcp://benternet.backup.pxl-ea-ict.be:24042");
    zmq_setsockopt (reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));


    puts("to receive");
    puts(RecieveConcat);
    printf("%li\n",strlen(RecieveConcat));
    puts("to Send");
 
    zmq_send(sender,SendConcat,strlen(SendConcat),0);
    puts(SendConcat);
    zmq_recv(reciever,buffer,5000 , 0); 
    printf ("Recieved: %s\n", buffer);
   
   while(arrayToScore(playerHand) < 21 && arrayToScore(computerHand) < 21)
	{
		printf("Do you want to continue y/n?: ");
		scanf("%s",doorgaan);
		//strtok(doorgaan, "\n");
		strcpy(SendConcat,"BlackJackService>Client>");
		strcat(SendConcat,name);
		strcat(SendConcat,">");
		strcat(SendConcat,doorgaan);
		zmq_send(sender,SendConcat,strlen(SendConcat),0);
    		strcpy(RecieveConcat,"BlackJackService>Player>");
		puts(name);
		strcat(RecieveConcat,name);
		strcat(RecieveConcat,">PlayerHand>");
		puts("what we'll subscribe to");
		puts(RecieveConcat);
		
   		zmq_setsockopt (reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));
   		
	   
		printf("recievedBuffer %s \n",buffer);
		zmq_recv(reciever,buffer,5000,0);	
		printf("we got this  %s\n",buffer);
		char *lastp = strrchr(buffer, '>');
		if (lastp != NULL) {
		printf("Last tokenp: '%s'\n",lastp+1 );
		printf("playerhand %s \n",lastp+1);
		}
	//	char* playerhand = buffer;
	//  	int playersize = strlen(playerhand);
	// 	char* playersuffix = playerhand + playersize;
	//	while (0 < playersize && playerhand[--playersize] != '>'){
	//	  if (playerhand[playersize] == '>') {
	//	    playersuffix = playerhand + playersize+ 1;
	//	    playerhand[playersize] = '\0';
	 //   	  }
	 //    	 }
	  
	  	
		
	  
               strcpy(RecieveConcat,"BlackJackService>Player>");
		strcat(RecieveConcat,name);
		strcat(RecieveConcat,">ComputerHand>");
		zmq_setsockopt (reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));
			zmq_recv(reciever,buffer,5000,0);

	char *lastc = strrchr(buffer, '>');
	if (lastc != NULL) {
        printf("Last tokenc: '%s'\n", lastc+1);
        	printf("Computerhand %s \n",lastc+1);
    }
 // char* computerhand = buffer;
  //int compsize = strlen(computerhand);
  //char* compsuffix = computerhand + compsize;
  //printf("%s\n",buffer);
//	while (0 < compsize && computerhand[--compsize] != '>'){
 //	  if (computerhand[compsize] == '>') {
//		    compsuffix = computerhand + compsize+ 1;
//		    computerhand[compsize] = '\0';
//	        	  }
//	     }
	
	   // *computerHand = *compsuffix;
	  //	*playerHand = *playersuffix;
	

if (lastc != NULL&&lastp != NULL ) {
visualize(9,lastp+1,lastc+1);
    }	



		

  

	//	strcpy(RecieveConcat,"BlackJackService>Player>");
	//	strcat(RecieveConcat,name);
	//	strcat(RecieveConcat,">Score>");
	//	zmq_setsockopt (reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));
	//	zmq_recv(reciever,buffer,5000,0);
	//	if(strcmp(buffer,"BlackJackService>Player>{name}>Score>WIN") > 0 )
	//	{
	//		printf("GRYFFINDOR WINS!!");
	//	}
	//	else if(strcmp(buffer,"BlackJackService>Player>{name}>Score>LOSE") > 0 )
	//	{
	//		printf("THE HOUSE ALLWAYS WINS, GET A LIFE GAMBLING ADDICT");
	//	}

		
		/*stiekeme easter egg*/
		 if(strcmp("Hi",doorgaan) == 0 || strcmp("Hello",doorgaan) == 0) { playEasterEgg(); }
	}
	
    zmq_close (sender);
    zmq_close (reciever);
    zmq_ctx_destroy (context);
}
