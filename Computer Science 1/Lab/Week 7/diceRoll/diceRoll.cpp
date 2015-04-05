/*

*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int rollDice();		// Rolls 2 dice and returns the sum. 
int rollDiceGame();

int main()
{
srand(time(NULL));
cout << "It took " << rollDiceGame() << " tries to roll your target number" << endl;
return 0;
}


int rollDice()
{
// Two dice and +2 since you must add one for each dice to shift the range from 0~5 to 1~6. 
return rand() % 6 + rand() % 6 + 2;
}

int rollDiceGame()
{
int targetNumber = 0,
	rollTally = 1;

do{
cout << "What number [2 ~ 12] would you like to roll for? ";
cin >> targetNumber;
if (targetNumber < 2 || targetNumber > 12) cout << "Not a valid selection!" << endl;
} while(targetNumber < 2 || targetNumber > 12);

while (rollDice() != targetNumber) rollTally++;

return rollTally;
}