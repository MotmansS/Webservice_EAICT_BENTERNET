/*
Blackjack: Code verwezenlijkt door Smolders Xander en Motmans Sam, 1PBEAI-C
Gebruik gemaakt van template gegeven door docent: Gilissen Koen, Vreys Frederik.
*/
#include "blackjack.h"

#include "zmq.h"

#include <assert.h>

#include <unistd.h>

char computerHand[] = "GGGGGGGGG";
char playerHand[] = "GGGGGGGGG";
int main(void) {
  char * computerhand;
  char * playerhand;

  zmq_msg_t message;
  zmq_msg_init( & message);

  printf("\033[0;32m"); //Groene console
  srand(time(NULL)); //Kaarten randomizen
  printIntro();

  char RecieveConcat[] = "BlackJackService>Player>";
  char SendConcat[] = "BlackJackService>Client>";
  char name[40];
  char doorgaan[10];
  char buffer[5001];
  char buffer_[5001];
  char _buffer_[5001];

  printf("Enter name:\n ");
  scanf("%s", name);

  strcat(SendConcat, name);

  void * context = zmq_ctx_new();
  void * sender = zmq_socket(context, ZMQ_PUSH);
  void * reciever = zmq_socket(context, ZMQ_SUB);

  strcat(RecieveConcat, name);
  zmq_connect(sender, "tcp://benternet.pxl-ea-ict.be:24041");
  zmq_connect(reciever, "tcp://benternet.pxl-ea-ict.be:24042");
  zmq_setsockopt(reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));

  zmq_send(sender, SendConcat, strlen(SendConcat), 0);
  puts(SendConcat);
  zmq_recv(reciever, buffer, 5000, 0);

  while (arrayToScore(playerHand) < 21 && arrayToScore(computerHand) < 21) {
    printf("Do you want to continue y/n?: ");
    scanf("%s", doorgaan);
    //strtok(doorgaan, "\n");
    strcpy(SendConcat, "BlackJackService>Client>");
    strcat(SendConcat, name);
    strcat(SendConcat, ">");
    strcat(SendConcat, doorgaan);
    puts(SendConcat);
    zmq_send(sender, SendConcat, strlen(SendConcat), 0);
    strcpy(RecieveConcat, "BlackJackService>Player>");
    puts(name);
    strcat(RecieveConcat, name);
    strcat(RecieveConcat, ">PlayerHand>");
    puts(RecieveConcat);

    if (strstr(doorgaan, "y") != NULL) {

      zmq_setsockopt(reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));

      zmq_recv(reciever, buffer, 5000, 0);
	puts(buffer);
      char * lastp = strrchr(buffer, '>');

      if (lastp != NULL) {
        playerhand = lastp + 1;
      }
      strcpy(RecieveConcat, "BlackJackService>Player>");
      strcat(RecieveConcat, name);
      strcat(RecieveConcat, ">ComputerHand>");
      zmq_setsockopt(reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));
      zmq_recv(reciever, buffer_, 5000, 0);
	puts(buffer_);
      char * lastc = strrchr(buffer_, '>');
      if (lastc != NULL) {
        computerhand = lastc + 1;
      }

      visualize(9, playerhand, computerhand);
    } 
    else if (strstr(doorgaan, "n") != NULL) {
      strcpy(RecieveConcat, "BlackJackService>Player>");
      strcat(RecieveConcat, name);
      strcat(RecieveConcat, ">Score>");
      zmq_setsockopt(reciever, ZMQ_SUBSCRIBE, RecieveConcat, strlen(RecieveConcat));
      zmq_recv(reciever, _buffer_, 5000, 0);
      puts(_buffer_);
      if (strstr(_buffer_, "WIN") != NULL) {printf("GRYFFINDOR WINS!!"); }
      else if (strstr(_buffer_, "LOSE") != NULL) {printf("THE HOUSE ALLWAYS WINS, GET A LIFE GAMBLING ADDICT");}
      break;
    } 
    else {printf("i cant quite understand you");}
    /*stiekeme easter egg*/
    if (strcmp("Hi", doorgaan) == 0 || strcmp("Hello", doorgaan) == 0) {playEasterEgg();}

  }
     zmq_close(sender);
  zmq_close(reciever);
 zmq_ctx_destroy(context);

}
