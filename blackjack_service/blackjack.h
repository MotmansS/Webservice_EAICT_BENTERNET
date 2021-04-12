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

void kaart1(int cardLine);
void kaart2(int cardLine);
void kaart3(int cardLine);
void kaart4(int cardLine);
void kaart5(int cardLine);
void kaart6(int cardLine);
void kaart7(int cardLine);
void kaart8(int cardLine);
void kaart9(int cardLine);
void kaart10(int cardLine);
void kaart11(int cardLine);
void kaart12(int cardLine);
void kaart13(int cardLine);

short int arrayToScore(char array[]);
void checkVictory(char playerHand[], char computerHand[]);
void fillArrayRandom(char array[], unsigned int player);
void printIntro(void);
void drawHand(char array[], short int cardLines);
void playBlackjack(void);
void visualize(short int cardLines, char playerHand[], char computerHand[]);

void playEasterEgg(void);
void drawMap(void);
#endif
