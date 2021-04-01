#include "blackjack.h"
/*
Function: Hands out the cards to the respective array.
Parameters: Char array, unsigned int player
Returns:/
*/
void fillArrayRandom(char array[], unsigned int player)
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
		printf("You have drawn the ace! Do you want it do be a 1 or a 11?\n");
		char tempString[20];
		while(1)
		{
			fgets(tempString,20,stdin);
			strtok(tempString, "\n");
			if(strcmp("11",tempString) == 0) { randomnumber = 14; break; }
			else if(strcmp("1",tempString) == 0) { randomnumber = 1; break; }
			else { printf("Ehm? Sorry, I don't quite understand that.\n"); }
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
void kaart1(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|A        |\t"); break;
		case 2:	printf("|+   *    |\t"); break;
		case 3: printf("|    !    |\t"); break;
		case 4: printf("|  *-+-*  |\t"); break;
		case 5: printf("|    |    |\t"); break;
		case 6: printf("|   ~~~  +|\t"); break;
		case 7: printf("|        V|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart2(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|2        |\t"); break;
		case 2:	printf("|+        |\t"); break;
		case 3: printf("|    +    |\t"); break;
		case 4: printf("|         |\t"); break;
		case 5: printf("|    +    |\t"); break;
		case 6: printf("|        +|\t"); break;
		case 7: printf("|        Z|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart3(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|3        |\t"); break;
		case 2: printf("|+   +    |\t"); break;
		case 3: printf("|         |\t"); break;
		case 4: printf("|    +    |\t"); break;
		case 5: printf("|         |\t"); break;
		case 6: printf("|    +   +|\t"); break;
		case 7: printf("|        E|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart4(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|4        |\t"); break;
		case 2: printf("|+        |\t"); break;
		case 3: printf("|  +   +  |\t"); break;
		case 4: printf("|         |\t"); break;
		case 5: printf("|  +   +  |\t"); break;
		case 6: printf("|        +|\t"); break;
		case 7: printf("|        b|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart5(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|5        |\t"); break;
		case 2: printf("|+        |\t"); break;
		case 3: printf("|  +   +  |\t"); break;
		case 4: printf("|    +    |\t"); break;
		case 5: printf("|  +   +  |\t"); break;
		case 6: printf("|        +|\t"); break;
		case 7: printf("|        S|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart6(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|6        |\t"); break;
		case 2: printf("|+ +   +  |\t"); break;
		case 3: printf("|         |\t"); break;
		case 4: printf("|  +   +  |\t"); break;
		case 5: printf("|         |\t"); break;
		case 6: printf("|  +   + +|\t"); break;
		case 7: printf("|        9|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart7(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|7        |\t"); break;
		case 2: printf("|+ +   +  |\t"); break;
		case 3: printf("|    +    |\t"); break;
		case 4: printf("|  +   +  |\t"); break;
		case 5: printf("|         |\t"); break;
		case 6: printf("|  +   + +|\t"); break;
		case 7: printf("|        L|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}

}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart8(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|8 +   +  |\t"); break;
		case 2: printf("|+        |\t"); break;
		case 3: printf("|  +   +  |\t"); break;
		case 4: printf("|         |\t"); break;
		case 5: printf("|  +   +  |\t"); break;
		case 6: printf("|        +|\t"); break;
		case 7: printf("|  +   + 8|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart9(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|9 +   +  |\t"); break;
		case 2: printf("|+        |\t"); break;
		case 3: printf("|  +   +  |\t"); break;
		case 4: printf("|    +    |\t"); break;
		case 5: printf("|  +   +  |\t"); break;
		case 6: printf("|        +|\t"); break;
		case 7: printf("|  +   + 6|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart10(int cardLine)
{
	switch (cardLine) {
		case 0: printf(" _________ \t"); break;
		case 1: printf("|10+   +  |\t"); break;
		case 2: printf("|+   +    |\t"); break;
		case 3: printf("|  +   +  |\t"); break;
		case 4: printf("|         |\t"); break;
		case 5: printf("|  +   +  |\t"); break;
		case 6: printf("|    +   +|\t"); break;
		case 7: printf("|  +   +0l|\t"); break;
		case 8: printf(" ~~~~~~~~~ \t"); break;
	}
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart11(int cardLine)
{
    switch (cardLine) {
        case 0: printf(" _________ \t"); break;
        case 1: printf("|J /~~|_  |\t"); break;
        case 2: printf("|+ | o`,  |\t"); break;
        case 3: printf("|  | -|   |\t"); break;
        case 4: printf("| =~)+(_= |\t"); break;
        case 5: printf("|   |- |  |\t"); break;
        case 6: printf("|  `.o | +|\t"); break;
        case 7: printf("|  ~|__/ P|\t"); break;
        case 8: printf(" ~~~~~~~~~ \t"); break;
    }
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart12(int cardLine)
{
    switch (cardLine) {
        case 0: printf(" _________ \t"); break;
        case 1: printf("|Q |~~~|  |\t"); break;
        case 2: printf("|+ /o,o\\  |\t"); break;
        case 3: printf("|  \\_-_/  |\t"); break;
        case 4: printf("| _-~+_-~ |\t"); break;
        case 5: printf("|  /~-~\\  |\t"); break;
        case 6: printf("|  \\o`o/ +|\t"); break;
        case 7: printf("|  |___| Q|\t"); break;
        case 8: printf(" ~~~~~~~~~ \t"); break;
    }
}
/*
Function: Print a line of a card
Parameters: Int cardline(what line you want to print)
Returns:/
*/
void kaart13(int cardLine)
{
    switch (cardLine) {
        case 0: printf(" _________ \t"); break;
        case 1: printf("|K |/|\\|  |\t"); break;
        case 2: printf("|+ /o,o\\  |\t"); break;
        case 3: printf("|  \\_-_/  |\t"); break;
        case 4: printf("| ~-_-~-_ |\t"); break;
        case 5: printf("|  /~-~\\  |\t"); break;
        case 6: printf("|  \\o`o/ +|\t"); break;
        case 7: printf("|  |\\|/| X|\t"); break;
        case 8: printf(" ~~~~~~~~~ \t"); break;
    }
}
/*
Function: Prints introduction screen
Parameters:/
Returns:/
*/
void printIntro()
{
printf("d8b\n");
printf("88P\n");
printf("d88\n");
printf("?88   d8P  d8P d8888b888   d8888b d8888b   88bd8b,d88b  d8888b\n");
printf("d88  d8P' d8P'd8b_,dP?88  d8P' `Pd8P' ?88  88P'`?8P'?8bd8b_,dP\n");
printf("?8b ,88b ,88' 88b     88b 88b    88b  d88 d88  d88  88P88b\n");
printf("`?888P'888P'  `?888P'  88b`?888P'`?8888P'd88' d88'  88b`?888P'\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("d8P\n");
printf("d888888P\n");
printf("?88'   d8888b\n");
printf("88P   d8P' ?88\n");
printf("88b   88b  d88\n");
printf("`?8b  `?8888P'\n");
printf("\n");
printf("\n");
printf("\n");
printf("d8b       d8b                   d8b          d8,                   d8b\n");
printf("?88       88P                   ?88         `8P                    ?88\n");
printf("88b     d88                     88b                                88b\n");
printf("888888b 888   d888b8b   d8888b  888  d88'  d88   d888b8b   d8888b  888  d88'\n");
printf("88P `?8b?88  d8P' ?88  d8P' `P  888bd8P'   ?88  d8P' ?88  d8P' `P  888bd8P'\n");
printf("d88,  d88 88b 88b  ,88b 88b     d88888b      88b 88b  ,88b 88b     d88888b\n");
printf("d88'`?88P'  88b`?88P'`88b`?888P'd88' `?88b,   `88b`?88P'`88b`?888P'd88' `?88b,\n");
printf("					       )88\n");
printf("			  		     ,88P\n");
printf("`					    ?888P\n");



    printf("Haal meer dan je opponent, maar minder dan 22!\n");
}
/*
Function: Prints cards side by side
Parameters:char array[](the hand you wish to draw from),short int cardLines(the height of a card) 
Returns:/
*/
void drawHand(char array[], short int cardLines)
{
	for(int i=0;i<9;i++) { 	    //Kaarten bestaan uit 0-8 regels => 9regels
		for(int a=0;a<strlen(array);a++) { //Loop array af
			switch(array[a]){ 			   //Array positie
				case '1': kaart1(i); break;//ACE1
				case '2': kaart2(i); break;
				case '3': kaart3(i); break;
				case '4': kaart4(i); break;
				case '5': kaart5(i); break;
				case '6': kaart6(i); break;
				case '7': kaart7(i); break;
				case '8': kaart8(i); break;
				case '9': kaart9(i); break;
				case 'A': kaart10(i); break;
				case 'B': kaart11(i); break;//JACK
				case 'C': kaart12(i); break;//QUEEN
				case 'D': kaart13(i); break;//KING
				case 'E': kaart1(i); break; //ACE2
                case 'G': break; 
				default: printf("This element does not exist: %c",array[a]);break;
			}
		}
		printf("\n");
	}
	printf("\n");
	
}
/*
Function: Check who won the game
Parameters:char playerHand[], char computerHand[] (the two hands you wish to compare)
Returns:/
*/
void checkVictory(char playerHand[], char computerHand[])
{
	if(arrayToScore(playerHand) > 21 && arrayToScore(computerHand) > 21) { printf("Draw!\n"); exit(0); }
	else if(arrayToScore(playerHand) > 21) { printf("THE HOUSE ALLWAYS WINS\n"); exit(0); }
	else if (arrayToScore(playerHand) > arrayToScore(computerHand) && arrayToScore(playerHand) < 22) { printf("U WON\n"); }
 	else if(arrayToScore(playerHand) < arrayToScore(computerHand)) { printf("THE HOUSE ALLWAYS WINS\n"); exit(0); }
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
void visualize(short int cardLines, char playerHand[], char computerHand[])
{
	system("@cls||clear");
	puts("The house:\n");
	drawHand(computerHand, cardLines);
	puts("---------------------------------------------------------------------------------------------------- \n You:\n");
    drawHand(playerHand, cardLines);
}

void drawMap(){
	printf("\n\n");
	printf("__________--^-^-\\.             ____                             __----/^\\.\n");
	printf("|\\/.                \\__.      ___/   ||                        ___/       _/._-_    .\n");
	printf("|                      \\.    /.     /.                __    __/          /__/   \\/^^\\___-__.\n");
	printf("|                       L-^-/.     /.                 \\.\\_--                               \\.\n");
	printf("|                                 /                  _/                                 _/\\/.\n");
	printf("|.                               |                 _/.                            __ __/\n");
	printf(" \\.                              /.               /                           ___/.//\n");
	printf("  \\__                           /                |                           /    \\/.\n");
	printf("     \\________         __ _____.\\.                \\_.          ____--_   /\\_ \\    \n");
	printf("              \\__.    /  V.    \\ \\                  \\__      _/.      \\_/   //\n");
	printf("                 \\   /.         \\/.                    \\.  _/.             //\n");
	printf("                  \\_/.                                   \\_/             \n\n");
	printf("           UNITED STATES                                   SOVIET UNION\n");

}

void playEasterEgg(){
	printf("Password: ");
	char doorgaan[30];
	fgets(doorgaan,20,stdin);
	strtok(doorgaan, "\n");
		if(strcmp("Stan",doorgaan) == 0 || strcmp("Leon",doorgaan) == 0 || strcmp("stan",doorgaan) == 0 || strcmp("leon",doorgaan) == 0 || strcmp("Joshua",doorgaan) == 0 || strcmp("joshua",doorgaan) == 0) { 
			system("clear");
			printf("Hello Proffesor Gilissen shall we play a game?\n");
			fgets(doorgaan,20,stdin);
			strtok(doorgaan, "\n");
			if(strcmp("y",doorgaan) == 0 || strcmp("yes",doorgaan) == 0 || strcmp("Yes",doorgaan) == 0 || strcmp("list games",doorgaan) == 0 || strcmp("List games",doorgaan) == 0 || strcmp("List Games",doorgaan) == 0) { 
				system("clear");
				printf("Blackjack \nGlobal Thermo Nuclear War\n\n");
				fgets(doorgaan,30,stdin);
				strtok(doorgaan, "\n");
				if(strcmp("Global Thermo Nuclear War",doorgaan) == 0 || strcmp("global thermo nuclear war",doorgaan) == 0) { 
					drawMap();
				}
				else if(strcmp("blackJack",doorgaan) == 0 || strcmp("blackjack",doorgaan) == 0 || strcmp("Blackjack",doorgaan) == 0) { }
			}
		}
}
