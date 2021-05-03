#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <zmq.h>
#include <unistd.h>
#include <assert.h>
typedef enum { PLAYER_cpu, PLAYER_user } playerType;

void printIntro();

void kaart1(int cardLine,void *responder);
void kaart2(int cardLine,void *responder);
void kaart3(int cardLine,void *responder);
void kaart4(int cardLine,void *responder);
void kaart5(int cardLine,void *responder);
void kaart6(int cardLine,void *responder);
void kaart7(int cardLine,void *responder);
void kaart8(int cardLine,void *responder);
void kaart9(int cardLine,void *responder);
void kaart10(int cardLine,void *responder);
void kaart11(int cardLine,void *responder);
void kaart12(int cardLine,void *responder);
void kaart13(int cardLine,void *responder);

short int arrayToScore(char array[]);
void checkVictory(char playerHand[], char computerHand[]);
void fillArrayRandom(char array[], unsigned int player,void *responder);
void printIntro(void *responder);
void drawHand(char array[], short int cardLines,void *responder);
void playBlackjack(void *responder);
void visualize(short int cardLines, char playerHand[], char computerHand[],void *responder);

void playEasterEgg(void *responder);
void drawMap(void *responder);
#endif
