#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void insertString(vector<string>&, string, int);
void deleteString(vector<string>&, int);
void printString(const vector<string>&);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	string command, insertWord;
	int index;
	vector<string> wordList;
	
	while (!fin.eof())
	{
		fin >> command;
		if (command == "Insert")
		{
			fin >> insertWord;
			fin >> index;
			insertString(wordList, insertWord, index);
		}
		else if (command == "Delete")
		{
			fin >> index;
			deleteString(wordList, index);
		}
		else if (command == "Print")
		{
			printString(wordList);
		}
	}
	
	return 0;
}

void insertString(vector<string>& wordList, string givenString, int index)
{
	//cout << "Index is: " << index << endl << wordList.size() << " ? " << index << endl;   //Error checking
	
	// Expand the array to allow for the new string
	/*while(wordList.size() < index + 1)
	{
		wordList.push_back("");
		//cout << "Size is now :" << wordList.size() << endl;
	}*/
	
	// Error checking
	//wordList.insert(givenString, wordList.begin() + index);
	//wordList[index] = givenString;
	
	if(index > wordList.size())
	{
		cout << "Error! " << index << " is not within the bounds of the vector! \"" << givenString << "\" could not be saved!" << endl;
	}
	else
		wordList.insert(wordList.begin() + index, givenString);
}

void deleteString(vector<string>& wordList, int index)
{
	if(index < wordList.size() && index >= 0)
		wordList.erase(wordList.begin() + index);
	else
		cout << "The index " << index << " is not within the bounds of the vector. Could not delete." << endl;
}

void printString(const vector<string>& wordList)
{
	for (int i = 0; i < wordList.size(); i++)
	{	
		cout << i << "." << wordList[i] << endl;
	}
	cout << "End of vector" << endl << endl;
}

