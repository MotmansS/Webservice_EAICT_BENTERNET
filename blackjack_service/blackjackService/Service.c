#include "Service.h"
int drawCard(int *score,int *addition )
{

    switch ((rand() % 13) + 1)
    {
        case 1:  addition = 1;  break;
        case 2:  addition = 2;  break;
        case 3:  addition = 3;  break;
        case 4:  addition = 4;  break;
        case 5:  addition = 5;  break;
        case 6:  addition = 6;  break;
        case 7:  addition = 7;  break;
        case 8:  addition = 8;  break;
        case 9:  addition = 9;  break;
        case 10: addition = 10; break;
        case 11: addition = 11; break;
        case 12: addition = 10; break;
        case 13: addition = 10; break;
      

        default:
        break;
    }
    *score = *score + addition;
}
int playBlackjack(void *responder, int *score, int *addition)
{
    char * doorgaan;
	zmq_recv(*doorgaan,20,stdin);
    char* message = string(*score)+ string (*addition)
    if (toupper(*doorgaan)  == "Y")
    {
        drawCard(*score,*addition);
        zmq_send(responder,message,strlen(message));
    }
    
}