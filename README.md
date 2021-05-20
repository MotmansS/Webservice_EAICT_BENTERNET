# Welcome to the PBEAI-ICT Benternet blackjack service

This is the home of the PXL PBEAI-ICT Benternet blackjack service written by MotmansS.


# Prerequisites
To enjoy the blackjack service to the fullest a few prerequisites are needed for the best experience. 
All the links to these can be found below.
	
 - A Debian/Linux based operating system 
 - A working [Python 3](https://www.python.org/downloads/) install (preferably python 3.7) 
 - A [C compiler](https://gcc.gnu.org/) (GCC)
 - The files in the [rc](https://github.com/MotmansS/Webservice_EAICT_BENTERNET/tree/rc) branch of this repo

## Compiling

After downloading and/ or installing the prerequisites, it is now possible to compile the service! 
To do this the following steps have to be maintained:

 1. Open the terminal of choice
 2. Navigate to the folder where the rc branch is downloaded
 3. Compile by using the "gcc main.c blackjack.o -lzmq -o Blackjackserviceclient" command

 

## Running the client

To run the client, navigate to the location where the client was compiled and use the "./Blackjackserviceclient" command.

## Running the service

To run the service:

 1. Navigate to the folder where the rc branch was downloaded
 2. Use the command "python3 pub.py" to run the service

## Notes

If the client is stopped prematurely, the service will halt resulting in a non-working service.
Avoid this at any cost


