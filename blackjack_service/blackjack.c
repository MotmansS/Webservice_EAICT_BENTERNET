#include "blackjack.h"
/*
Function: Hands out the cards to the respective array.
Parameters: Char array, unsigned int player
Returns:/
*/
void fillArrayRandom(char array[], unsigned int player,void *responder)
{
	short int randomnumber = (rand()%12)+1; //13 Kaarten (ACE 1 & ACE 11 is zelfde)
	char randomchar;
	
	/* Checken voor het aas, CPU moet optimale waarde kunnen kiezen) */
	if(randomnumber == 1 && player == PLAYER_cpu) {
		if((arrayToScore(array)+11) <= 21) {  randomnumber = 14; }
	    if((arrayToScore(array)+11) > 21) {  randomnumber = 1; }
	}
	/* Speler mag ook kiezen als het aas gepresenteerd wordt */
	else if(randomnumber == 1 && player == PLAYER_user) { 
		zmq_send (responder,"You have drawn the ace! Do you want it do be a 1 or a 11?\n");
		char tempString[20];
		while(1)
		{
			zmq_recv (responder,tempString,20,0);
			strtok(tempString, "\n");
			if(strcmp("11",tempString) == 0) { randomnumber = 14; break; }
			else if(strcmp("1",tempString) == 0) { randomnumber = 1; break; }
			else { zmq_send (responder,"Ehm? Sorry, I don't quite understand that.\n"); }
		}
	}
	
    switch (randomnumber)
    {
        case 1 : randomchar = '1'; break; //ACE 1
        case 2 : randomchar = '2'; break;
        case 3 : randomchar = '3'; break;
        case 4 : randomchar = '4'; break;
        case 5 : randomchar = '5'; break;
        case 6 : randomchar = '6'; break;
        case 7 : randomchar = '7'; break;
        case 8 : randomchar = '8'; break;
        case 9 : randomchar = '9'; break;
		case 10 : randomchar = 'A'; break; //10
		case 11 : randomchar = 'B'; break; //King
		case 12 : randomchar = 'C'; break; //Queen
		case 13 : randomchar = 'D'; break; //Jack
		case 14 : randomchar = 'E'; break; //ACE 11
		default: randomchar = 'G'; break;
	}
    for (size_t i = 0; i < strlen(array); i++) { if(array[i] == 'G') { array[i] = randomchar; break; } }
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart1(int cardLine, void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|A        |\t",13,0); break;
		case 2:	zmq_send (responder,"|+   *    |\t",13,0); break;
		case 3: zmq_send (responder,"|    !    |\t",13,0); break;
		case 4: zmq_send (responder,"|  *-+-*  |\t",13,0); break;
		case 5: zmq_send (responder,"|    |    |\t",13,0); break;
		case 6: zmq_send (responder,"|   ~~~  +|\t",13,0); break;
		case 7: zmq_send (responder,"|        V|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart2(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|2        |\t",13,0); break;
		case 2:	zmq_send (responder,"|+        |\t",13,0); break;
		case 3: zmq_send (responder,"|    +    |\t",13,0); break;
		case 4: zmq_send (responder,"|         |\t",13,0); break;
		case 5: zmq_send (responder,"|    +    |\t",13,0); break;
		case 6: zmq_send (responder,"|        +|\t",13,0); break;
		case 7: zmq_send (responder,"|        Z|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart3(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|3        |\t",13,0); break;
		case 2: zmq_send (responder,"|+   +    |\t",13,0); break;
		case 3: zmq_send (responder,"|         |\t",13,0); break;
		case 4: zmq_send (responder,"|    +    |\t",13,0); break;
		case 5: zmq_send (responder,"|         |\t",13,0); break;
		case 6: zmq_send (responder,"|    +   +|\t",13,0); break;
		case 7: zmq_send (responder,"|        E|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart4(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|4        |\t",13,0); break;
		case 2: zmq_send (responder,"|+        |\t",13,0); break;
		case 3: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 4: zmq_send (responder,"|         |\t",13,0); break;
		case 5: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 6: zmq_send (responder,"|        +|\t",13,0); break;
		case 7: zmq_send (responder,"|        b|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart5(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|5        |\t",13,0); break;
		case 2: zmq_send (responder,"|+        |\t",13,0); break;
		case 3: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 4: zmq_send (responder,"|    +    |\t",13,0); break;
		case 5: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 6: zmq_send (responder,"|        +|\t",13,0); break;
		case 7: zmq_send (responder,"|        S|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart6(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|6        |\t",13,0); break;
		case 2: zmq_send (responder,"|+ +   +  |\t",13,0); break;
		case 3: zmq_send (responder,"|         |\t",13,0); break;
		case 4: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 5: zmq_send (responder,"|         |\t",13,0); break;
		case 6: zmq_send (responder,"|  +   + +|\t",13,0); break;
		case 7: zmq_send (responder,"|        9|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart7(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|7        |\t",13,0); break;
		case 2: zmq_send (responder,"|+ +   +  |\t",13,0); break;
		case 3: zmq_send (responder,"|    +    |\t",13,0); break;
		case 4: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 5: zmq_send (responder,"|         |\t",13,0); break;
		case 6: zmq_send (responder,"|  +   + +|\t",13,0); break;
		case 7: zmq_send (responder,"|        L|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}

}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart8(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|8 +   +  |\t",13,0); break;
		case 2: zmq_send (responder,"|+        |\t",13,0); break;
		case 3: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 4: zmq_send (responder,"|         |\t",13,0); break;
		case 5: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 6: zmq_send (responder,"|        +|\t",13,0); break;
		case 7: zmq_send (responder,"|  +   + 8|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart9(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|9 +   +  |\t",13,0); break;
		case 2: zmq_send (responder,"|+        |\t",13,0); break;
		case 3: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 4: zmq_send (responder,"|    +    |\t",13,0); break;
		case 5: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 6: zmq_send (responder,"|        +|\t",13,0); break;
		case 7: zmq_send (responder,"|  +   + 6|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart10(int cardLine,void *responder)
{
	switch (cardLine) {
		case 0: zmq_send (responder," _________ \t",13,0); break;
		case 1: zmq_send (responder,"|10+   +  |\t",13,0); break;
		case 2: zmq_send (responder,"|+   +    |\t",13,0); break;
		case 3: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 4: zmq_send (responder,"|         |\t",13,0); break;
		case 5: zmq_send (responder,"|  +   +  |\t",13,0); break;
		case 6: zmq_send (responder,"|    +   +|\t",13,0); break;
		case 7: zmq_send (responder,"|  +   +0l|\t",13,0); break;
		case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart11(int cardLine,void *responder)
{
    switch (cardLine) {
        case 0: zmq_send (responder," _________ \t",13,0); break;
        case 1: zmq_send (responder,"|J /~~|_  |\t",13,0); break;
        case 2: zmq_send (responder,"|+ | o`,  |\t",13,0); break;
        case 3: zmq_send (responder,"|  | -|   |\t",13,0); break;
        case 4: zmq_send (responder,"| =~)+(_= |\t",13,0); break;
        case 5: zmq_send (responder,"|   |- |  |\t",13,0); break;
        case 6: zmq_send (responder,"|  `.o | +|\t",13,0); break;
        case 7: zmq_send (responder,"|  ~|__/ P|\t",13,0); break;
        case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
    }
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart12(int cardLine,void *responder)
{
    switch (cardLine) {
        case 0: zmq_send (responder," _________ \t",13,0); break;
        case 1: zmq_send (responder,"|Q |~~~|  |\t",13,0); break;
        case 2: zmq_send (responder,"|+ /o,o\\  |\t",13,0); break;
        case 3: zmq_send (responder,"|  \\_-_/  |\t",13,0); break;
        case 4: zmq_send (responder,"| _-~+_-~ |\t",13,0); break;
        case 5: zmq_send (responder,"|  /~-~\\  |\t",13,0); break;
        case 6: zmq_send (responder,"|  \\o`o/ +|\t",13,0); break;
        case 7: zmq_send (responder,"|  |___| Q|\t",13,0); break;
        case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
    }
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart13(int cardLine,void *responder)
{
    switch (cardLine) {
        case 0: zmq_send (responder," _________ \t",13,0); break;
        case 1: zmq_send (responder,"|K |/|\\|  |\t",13,0); break;
        case 2: zmq_send (responder,"|+ /o,o\\  |\t",13,0); break;
        case 3: zmq_send (responder,"|  \\_-_/  |\t",13,0); break;
        case 4: zmq_send (responder,"| ~-_-~-_ |\t",13,0); break;
        case 5: zmq_send (responder,"|  /~-~\\  |\t",13,0); break;
        case 6: zmq_send (responder,"|  \\o`o/ +|\t",13,0); break;
        case 7: zmq_send (responder,"|  |\\|/| X|\t",13,0); break;
        case 8: zmq_send (responder," ~~~~~~~~~ \t",13,0); break;
    }
}
/*
Function: Prints introduction screen
Parameters:/
Returns:/
*/
void printIntro(void *responder)
{
zmq_send (responder,"d8b\n",5,0);
zmq_send (responder,"88P\n",5,0);
zmq_send (responder,"d88\n",5,0);
zmq_send (responder,"?88   d8P  d8P d8888b888   d8888b d8888b   88bd8b,d88b  d8888b\n",64,0);
zmq_send (responder,"d88  d8P' d8P'd8b_,dP?88  d8P' `Pd8P' ?88  88P'`?8P'?8bd8b_,dP\n",64,0);
zmq_send (responder,"?8b ,88b ,88' 88b     88b 88b    88b  d88 d88  d88  88P88b\n",60,0);
zmq_send (responder,"`?888P'888P'  `?888P'  88b`?888P'`?8888P'd88' d88'  88b`?888P'\n",64,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"d8P\n",5,0);
zmq_send (responder,"d888888P\n",10,0);
zmq_send (responder,"?88'   d8888b\n"15,0);
zmq_send (responder,"88P   d8P' ?88\n"16,0);
zmq_send (responder,"88b   88b  d88\n",16,0);
zmq_send (responder,"`?8b  `?8888P'\n"16,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"\n",2,0);
zmq_send (responder,"d8b       d8b                   d8b          d8,                   d8b\n",72,0);
zmq_send (responder,"?88       88P                   ?88         `8P                    ?88\n",72,0);
zmq_send (responder,"88b     d88                     88b                                88b\n",72,0);
zmq_send (responder,"888888b 888   d888b8b   d8888b  888  d88'  d88   d888b8b   d8888b  888  d88'\n",78,0);
zmq_send (responder,"88P `?8b?88  d8P' ?88  d8P' `P  888bd8P'   ?88  d8P' ?88  d8P' `P  888bd8P'\n",77,0);
zmq_send (responder,"d88,  d88 88b 88b  ,88b 88b     d88888b      88b 88b  ,88b 88b     d88888b\n",76,0);
zmq_send (responder,"d88'`?88P'  88b`?88P'`88b`?888P'd88' `?88b,   `88b`?88P'`88b`?888P'd88' `?88b,\n",80,0);
zmq_send (responder,"					       )88\n",17,0);
zmq_send (responder,"			  		     ,88P\n",18,0);
zmq_send (responder,"`					    ?888P\n",17,0);



    zmq_send (responder,"Haal meer dan je opponent, maar minder dan 22!\n",48,0);
}
/*
Function: Prints cards side by side
Parameters:char array[](the hand you wish to draw from),short int cardLines(the height of a card) 
Returns:/
*/
void drawHand(char array[], short int cardLines,void *responder)
{
	for(int i=0;i<9;i++) { 	    //Kaarten bestaan uit 0-8 regels => 9regels
		for(int a=0;a<strlen(array);a++) { //Loop array af
			switch(array[a]){ 			   //Array positie
				case '1': kaart1(i,*responder); break;//ACE1
				case '2': kaart2(i,*responder); break;
				case '3': kaart3(i,*responder); break;
				case '4': kaart4(i,*responder); break;
				case '5': kaart5(i,*responder); break;
				case '6': kaart6(i,*responder); break;
				case '7': kaart7(i,*responder); break;
				case '8': kaart8(i,*responder); break;
				case '9': kaart9(i,*responder); break;
				case 'A': kaart10(i,*responder); break;
				case 'B': kaart11(i,*responder); break;//JACK
				case 'C': kaart12(i,*responder); break;//QUEEN
				case 'D': kaart13(i,*responder); break;//KING
				case 'E': kaart1(i,*responder); break; //ACE2
                case 'G': break; 
				default: 
				zmq_send (responder,"This element does not exist: %c",32,0);
				zmq_send (responder,array[a],1,0);
				break;
			}
		}
		zmq_send (responder,"\n",2,0);
	}
	zmq_send (responder,"\n",2,0);
	
}
/*
Function: Check who won the game
Parameters:char playerHand[], char computerHand[] (the two hands you wish to compare)
Returns:/
*/
void checkVictory(char playerHand[], char computerHand[], void *responder)
{
	if(arrayToScore(playerHand) > 21 && arrayToScore(computerHand) > 21) { zmq_send (responder,"Draw!\n",7,0); exit(0); }
	else if(arrayToScore(playerHand) > 21) { zmq_send (responder,"THE HOUSE ALLWAYS WINS\n",24,0); exit(0); }
	else if (arrayToScore(playerHand) > arrayToScore(computerHand) && arrayToScore(playerHand) < 22) { zmq_send (responder,"U WON\n",7,0); }
 	else if(arrayToScore(playerHand) < arrayToScore(computerHand)) { zmq_send (responder,"THE HOUSE ALLWAYS WINS\n",24,0); exit(0); }
}
/*
Function: Calculates the value of the players hand
Parameters:char array[] (the hand you wish to value)
Returns:score
*/
short int arrayToScore(char array[])
{
	short int score = 0;
	for (size_t i = 0; i < strlen(array); i++)
	{
	    switch (array[i])
    	{
        case '1' : score = score + 1; break;
        case '2' : score = score + 2; break;
        case '3' : score = score + 3; break;
        case '4' : score = score + 4; break;
        case '5' : score = score + 5; break;
        case '6' : score = score + 6; break;
        case '7' : score = score + 7; break;
        case '8' : score = score + 8; break;
        case '9' : score = score + 9; break;
		case 'A' : score = score + 10; break;
		case 'B' : score = score + 10; break;
		case 'C' : score = score + 10; break;
		case 'D' : score = score + 10; break;
		case 'E' : score = score + 11; break;
		default: score = score + 0; break;
		}
	}
	return score;
}
/*
Function: visualize everything in game
Parameters:short int cardLines (height of cards), char playerHand[], char computerHand[] (two arrays)
Returns:/
*/
void visualize(short int cardLines, char playerHand[], char computerHand[],void *responder)
{
	zmq_send(responder,"cls",4,0);
	puts("The house:\n");
	drawHand(responder,computerHand, cardLines);
	puts("---------------------------------------------------------------------------------------------------- \n You:\n");
    drawHand(responder,playerHand, cardLines);
}

void drawMap(void *responder){
	zmq_send (responder,"\n\n",3,0);
	zmq_send (responder,"__________--^-^-\\.             ____                             __----/^\\.\n",87,0);
	zmq_send (responder,"|\\/.                \\__.      ___/   ||                        ___/       _/._-_    .\n",94,0);
	zmq_send (responder,"|                      \\.    /.     /.                __    __/          /__/   \\/^^\\___-__.\n",94,0);
	zmq_send (responder,"|                       L-^-/.     /.                 \\.\\_--                               \\.\n",95,0);
	zmq_send (responder,"|                                 /                  _/                                 _/\\/.\n",95,0);
	zmq_send (responder,"|.                               |                 _/.                            __ __/\n",87,0);
	zmq_send (responder," \\.                              /.               /                           ___/.//\n",87,0);
	zmq_send (responder,"  \\__                           /                |                           /    \\/.\n",87,0);
	zmq_send (responder,"     \\________         __ _____.\\.                \\_.          ____--_   /\\_ \\    \n",80,0);
	zmq_send (responder,"              \\__.    /  V.    \\ \\                  \\__      _/.      \\_/   //\n",80,0);
	zmq_send (responder,"                 \\   /.         \\/.                    \\.  _/.             //\n",79,0);
	zmq_send (responder,"                  \\_/.                                   \\_/             \n\n",76,0);
	zmq_send (responder,"           UNITED STATES                                   SOVIET UNION\n",73,0);
		wait(1000);
	zmq_send (responder,"5\n",3,0);
		wait(1000);
	zmq_send (responder,"4\n",3,0);
		wait(1000);
	zmq_send (responder,"3\n",3,0);
		wait(1000);
	zmq_send (responder,"2\n",3,0);
		wait(1000);
	zmq_send (responder,"1\n",3,0);
		wait(1000);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@=@@@==--=====@@@==========---=========-----=@=====-=-------- -----===========----------===-  --------------==============@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@@@@==--====@@@===@@===-----==@==------ --=======------------  --------------------------===--   ----------===@@==@@@=======@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=---===@@====@@==------==@==--- --- -==@@===----------  ---  --  ---  ------------------====- -------========@@@@@@=========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=======@@====@==---========-    ---  ==@@@=====---------  ---  --   -   -------===---==----====-------==========@@@@===========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=======@@@=======@@@=====---======----    ---  -=@=======@@=====-==-   --  ---       -------=======---==@@=----- -==========@@@@===========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=======@@@==========-======---====-  ---------- -=====-==-======@@@===-  -=-  ---      --------====@====-==@@===-----===@@======@@@===========@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@=====@@=@@@@======@@=---====-----=--------------=---==-==-------=====@@@@==-=====----   --   -------==@@@======@@@@=====--===@=====@@@@@=========@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@=====@@=@@@@===@==@@=- -=--=--=--== --------    -----=--==---    -----==@@@@=-=@@@@=- --  ---   --- --==@@@@@====@@@@====---==@=====@@@@@===========@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@=====@==@@@@===@@@@@=---=------=------------    -----==------        ----====@=@@=@@@@===-  ----  ---  --==@@@@====@@@@===-=====@===-@@@@@@@@======--=@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@=======@@@@===@@@@==- -==---  -=-----=-----   -------=-=----          ----==-=@@@@@@===@@=-   --=-----  --==@@@@@==@@@@=@@=-====@@====@@@@@@@@=========@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@=========@@@@==@@@@===- -=-==--  -=--------=-   -------=====---             -==--@@=@@@@=--@@@-    --====-  --==@@@@@@=@@@==@======@@==@==@@@@@@@@======@===@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@=====@======@@==@@=====---===---  -----=----=   ---=---====-=---              -==-=@=-=@@@=--@@@=      -=@===--==@@@@@@@@@@========@@=@@====@@@@@@@@=================@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@===@@@===@@@@===@@==@==-====--=-----=-=------  --==---====-------              -=-=@=--=@@@@=-=@@=----   -=@@=-===@@@@@@@@@============@@===@@@@@@@=@@@@@@@@@@@@=========@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@===@@@@==@@@@@======@@===-===---==---=-==--=-=----==---==-==---=---             ----=@=---=@@@@=-@@@=-------==@@@===@@@@@@@@@@=========@=@@@@==@@@@@@@@@@@@@@@@@@@@@@====@==@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@=====@@@@@@@@@====@==@@====@@===--==--=-==--===---===--==-===---====--            ---=@=---==@@@@=-=@@----=@=--=@@@@@@@@@@@@@@@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@===@@@@=@@@@@@@=@@@@@@@@@@=@@@@@@====--=====-======--====---===--======-           ----@=-----=@@@@=-@@===@@@=====@@@@@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@===@@@@@@@@@@@@==@@@@@@@@@@@=@==@@@@@@@======-====----==-----==-=--======-           ---@@      -=@@@==@@@@==@@@====@=@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@===@@@@@@@@@@@@@=@@@@@@@@@@@=@@@@=@@@@@@==========---===------==-====@=====-      ----==-=@-  ---=@@@@@@@@@====@=====@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@==@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@======@=--===------=-=====--=======-     ------- =@-=@@@@@@@@@==@@@==-=@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@==@==@==----- ----====--=====--==-         -==@@@=====@@@@=-=@@=---=====@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@=@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@====-     -------====--=-- ---       -==@@=@=-----=@@@=--@@----=---@=@@@@@@@=@=@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@=@@@@@@@@@@@@=@@@@=@@@@@@@@@@@@@@@@@@@@@@@@==-@=---------        ------------  -=- --==========@=--  -=@@---=@-  -- =@====@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@==@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@=====@@@@=@@@@@@@@@@@@@@@@@@@@@@@@=-==  -                ---------------=----===--------==========---==-- -=----==@@=@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@====@==@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@=====@@@@=@@=@=@@@@@@@@@@@@@@@@@@@@===   --              -------------------------------  --=====---- -===--    --====@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@==--=@==@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@====@@@@@=@@==@@@@@@@@@@@@@@@@@@@@==@- -----     -----   ----------------------------------------       -----    --=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@==---====@==@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@=====@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@=@=-   ---------==---   ---=-------------------    --------====-------------   --=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@==----======@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==------=======@@===-------==--------==----==----------====================-- --=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@====@==----======@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@========-=--====-----======-=======@@@@@@@@@@@@===========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@==----=======@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=========--------======@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==--=========@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@@==@@@@@@@@@@==---     --==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=========@====@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=====--==--@@@@@@@@@=--        --=@@@@@@@@===@@===--==@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@========@=@@====@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@====@=====--======@@@@@@@=--          -==@@@@@@===@@==-==---@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@=======@@@@====@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@=========@@@@@@@@@@===-----------====@@@@@=-             --=@@@@@@@===========@====@@@@@@@@@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@@@@====@@@@====@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-----====---======@@@@@@@====@@@========--                 --=@@@@@@===-----=====@@@@@@=====@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@====@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-  -===--------------===========----          -------          --===@@@@@@@@@@@@@@@@===--======@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@=@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=----                                       --                      ----=====@=====-----------========@@@@@@@@@@@@@@@@@@=@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==---                                    ---                                ----          --------===@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@===@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@====-                                                                                    -     =====@@@@@@@@@@@@@@@@@@=@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@====-                                                                                      -==@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@===--                       ----                          ---          ----           ---===-=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@=@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@==@@===-----                 --==                                ---    -===             --==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@=@@@@@@@@@@@@@@@=@@@=@@@@@@@@@@@@@@@@@=-===----                 --=@@-    -- --                       -===-----==-            --==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@=@@@@@@@@@@@@@@@@@=- -==----              --==@@===---=======----------======--  --===========-           --====@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@==@==@@@@@@@@@@@@@@@@@@=- ----------        ----==-- -@@@@@@@@@@@@@========@@@@@@@====---==@@@=@@=-         ----====@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@=====@@@@@@@@@@@@@@@@@@@@=-  ---=-------------==-     =@@@@@@@@@@@=================-=--   -==@@===@----    ----=====@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@====@@@@@@@@@@@@@@@@@@@@@@=  -=========@@===@=-      -==@@@@@@@===================----     -====@@==--------=====@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@=--=@@@@@=@@====---       --==========----====-=--==-----       --================@@@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@@@@@@@@-               -=======----===-----------         -==============@@@@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@=@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@========@@@=-------- --  -----=========-==========----    -------===========@@@@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@===@@@@@@@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@@@@@@=======@@@@@======@@@@@@===@@@@@@@@@@@==@@@@@@@===========================@@@@@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@==@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@======@@@@@@@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@=@@@@@@@@@@@@=@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@@======@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@==@@@@@@@@@@@=@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@====@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@@=====================@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@==@@@@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@@@@@@@=======================@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@=@@@@@@@@@@@@======@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@====@@@@@-- ---====@@@==@@@@@@@@@@@@@@@@@@@@@@@@@=====------=============@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@===-=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@====@@@@=------------=--=@===@@@@===@=-==========------  ---==========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==-=@@@@@@@@@==@@@@@@@@@@@@@@@@@@@@@@@==-=@@@@@===-=---====--=========-===========--------    ----======@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-===@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@==--==@@@@@@@@@@@============================----      ----====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@======@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=----=@@@@@@@@@@@@@@@@@@====================-     -----====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===--==@@@@@@@@@===============----===-==----   ----====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@==========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=========@@@@==========------     -- ------------=====@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@======-===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@======----------------     ---   -----------===========@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@======---===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==----- -              -===------=--================@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@",200,0);
zmq_send (responder,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@==---===@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=====-----    --------------=====================@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@",200,0);



}

void playEasterEgg(void *responder){
	zmq_send (responder,"Password: ");
	char doorgaan[30];
	zmq_recv(doorgaan,20,stdin);
	strtok(doorgaan, "\n");
		if(strcmp("Stan",doorgaan) == 0 || strcmp("Leon",doorgaan) == 0 || strcmp("stan",doorgaan) == 0 || strcmp("leon",doorgaan) == 0 || strcmp("Joshua",doorgaan) == 0 || strcmp("joshua",doorgaan) == 0) { 
			system("");
			zmq_send (responder,"Hello Deus Stukken shall we play a game?\n",48,0);
			zmq_recv(responder,doorgaan,30,0);
			strtok(doorgaan, "\n");
			if(strcmp("y",doorgaan) == 0 || strcmp("yes",doorgaan) == 0 || strcmp("Yes",doorgaan) == 0 || strcmp("list games",doorgaan) == 0 || strcmp("List games",doorgaan) == 0 || strcmp("List Games",doorgaan) == 0) { 
				system("clear");
				zmq_send (responder,"Blackjack \nGlobal Thermo Nuclear War\n\n",39,0);
				zmq_recv(responder,doorgaan,30,0);
				strtok(doorgaan, "\n");
				if(strcmp("Global Thermo Nuclear War",doorgaan) == 0 || strcmp("global thermo nuclear war",doorgaan) == 0) { 
					drawMap();
				}
				else if(strcmp("blackJack",doorgaan) == 0 || strcmp("blackjack",doorgaan) == 0 || strcmp("Blackjack",doorgaan) == 0) { }
			}
		}
}
