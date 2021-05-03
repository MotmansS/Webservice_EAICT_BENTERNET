#include "Service.h"

int main(int argc, char const *argv[])
{
    
    void *context = zmq_ctx_new();
	void *responder = zmq_socket(context, ZMQ_REP);
	int rc = zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);
    srand(time(NULL));	
    int score;
    int addition;
    playBlackjack(responder,score,addition);
        /* code */
    return 0;
}
