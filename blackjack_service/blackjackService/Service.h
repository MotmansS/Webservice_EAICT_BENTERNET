#ifndef _SERVICE_H_
#define _SERVICE_H_
#include <stdio.h>
#include <stdlib.h>
#include <zmq.h>
#include <string.h>
int drawCard(int *score,int *addition );
int playBlackjack(void *responder, int *score, int *addition);
#endif