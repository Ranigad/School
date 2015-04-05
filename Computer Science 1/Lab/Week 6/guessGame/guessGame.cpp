#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

string fileName = "hiscore.txt";

int main()
{
	ifstream inHiScore;
	ofstream outHiScore;
	
	outHiScore.open(fileName.c_str);
	inHiScore.open(fileName.c_str);
	
	srand(time(0));
	int guess = 0;
	int correctNumber = rand() % 100 + 1;
	int highScore = 0, guesses = 0;
	string name;

	
	inHiScore >> highScore >> name;

	cout << endl << "Guessing Game!"
		<< endl << "Previous High Score [" << highScore << "] was set by [" << name << "]" << endl
		<< endl << "Enter a guess for a number between 1 and 100: ";
	cin >> guess;
	
	inHiScore.close();	
		
	while (guess != correctNumber)
	{
	if (guess > correctNumber) cout << "Your guess was too high!" << endl;
	else cout << "Your guess was too low!" << endl;

	cout << "Enter a guess: ";
	cin >> guess;
	guesses++;
	}
	
	cout << "Congratulations! You win!" << endl;
	if (guesses < highScore)
	{cout << "Great job! Your score of " << guesses << " beat the old high score of " << highScore <<"!"
		<< endl << "Enter your name to save your new high score: ";
	cin >> name;}
	
	outHiScore << guesses << name;
	
return 0;
}
