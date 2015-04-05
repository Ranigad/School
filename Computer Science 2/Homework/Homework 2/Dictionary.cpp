#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include "Dictionary.h"
using namespace std;

// Initializing static variables
bool Dictionary::failure = false;
bool Dictionary::success = true;

/***************************************************************************
 * ~Dictionary                                                             *
 *                                                                         *
 * The destructor                                                          *
 ***************************************************************************/
Dictionary::~Dictionary()
{
}

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes constant maxWordsInDict to 10000 and maxWordsPerFile to 100 *
 * Initializes words in dictionary count to 0 and words in each file to 0  *
 ***************************************************************************/
Dictionary::Dictionary() : maxWordsInDict(10000), maxWordsPerFile(100)
{
	totalWordsInDict = 0;
	for(int i = 0; i < LETTERSOFTHEALPHABET; i++)
		numOfWordsInFile[i] = 0;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Initializes constant maxWordsInDict and maxWordsPerFile to passed in #  *
 * Initializes words in dictionary count to 0 and words in each file to 0  *
 ***************************************************************************/
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords) : 
maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords)
{
	totalWordsInDict = 0;
	for(int i = 0; i < LETTERSOFTHEALPHABET; i++)
		numOfWordsInFile[i] = 0;
}

/***************************************************************************
 * AddAWord                                                                *
 *                                                                         *
 * Takes in a word as a parameter and adds it the correct .txt file        *
 ***************************************************************************/
bool Dictionary::AddAWord(string word)
{
	string fileName = fileNamer(word);	// Gets the file name
	char alphaIndex = toupper(word[0]) - 'A';	// Gets the correct index for 
												// Words in file array
	string lowerCaseWord = wordToLower(word);	// Saves word in all lowercase
	
	ofstream fout;
	fout.open(fileName.data(), ios::app);	// Output stream that appends to file
	
	if(totalWordsInDict >= maxWordsInDict)
	{
		// Checks for the maximum number of words in the dictionary
		cout << endl << "Too many words in the dictionary!" << endl;
		return failure;
	}	
	else if(SearchForWord(lowerCaseWord))
	{
		// Checks if the word is already in the dictionary
		cout << endl << "\"" << lowerCaseWord 
			<< "\" already exists in dictionary!" << endl;
		return failure;
	}
	else if(numOfWordsInFile[alphaIndex] >= maxWordsPerFile)
	{
		// Checks if there are too many words inside of the file
		cout << endl << "Too many words in the " << toupper(lowerCaseWord[0]) 
			<< " section!" << endl;
		return failure;
	}
	
	fout << lowerCaseWord << endl;	// Output
	
	if(SearchForWord(lowerCaseWord))
	{
		// Double checks to make sure the output was successful
		totalWordsInDict++;
		numOfWordsInFile[alphaIndex]++;
		return success;
	}
	else
		return failure;
	
}

/***************************************************************************
 * DeleteAWord                                                             *
 *                                                                         *
 * Removes the word that is passed in from the corresponding .txt file     *
 ***************************************************************************/
bool Dictionary::DeleteAWord(string word)
{
	string fileName = fileNamer(word);
	string lowerCaseWord = wordToLower(word);
	string importedWord;
	vector<string> dictionary; // Vector to store the file and parse for word
	ifstream fin;
	ofstream fout;
	fin.open(fileName.data());
	
	while (fin >> importedWord)
	{
		// Imports words from file one by one and adds to the vector
		dictionary.push_back(importedWord);
	}
	
	fin.close();
	
	// Clears the file. The contents are stored in the vector.
	fout.open(fileName.data());
	fout << "";
	fout.close();
	
	while(dictionary.size() != 0)
	{
		if(lowerCaseWord.compare(dictionary.back()) == 0)
		{
			/* If the last word in the vector is the same as the word to be
				removed, then decrement the necessary values and then do nothing
				it will be removed by the pop_back method after the if check */
			totalWordsInDict--;
			numOfWordsInFile[toupper(lowerCaseWord[0]) - 'A']--;
		}
		else
		{
			/* If these are not the words you are looking for, add it back into
				the file*/
			AddAWord(dictionary.back());
		}
		dictionary.pop_back();	// Removes the last stored word.
	}
	
	// Double checks to make sure that the word is no longer in the file.
	if(SearchForWord(lowerCaseWord))
		return failure;
	else
		return success;
	
}

/***************************************************************************
 * SearchForWord                                                           *
 *                                                                         *
 * Checks to see if a given word is already in the dictionary (.txt)       *
 ***************************************************************************/
bool Dictionary::SearchForWord(string word)
{
	string fileName = fileNamer(word);
	string importedWord;
	ifstream fin;
	fin.open(fileName.data());
	
	while(fin >> importedWord)
	{
		// Imports each word compares to the lowercase version of the given word
		if(importedWord == wordToLower(word))
			return success;
	} 
	
	return failure;
}

/***************************************************************************
 * PrintAFileInDict                                                        *
 *                                                                         *
 * Prints all the words inside of a given file with a maximum of 5 words   *
 * per line. Formatted for words up to 15 letters. May need user to expand *
 * their client.														   *
 ***************************************************************************/
bool Dictionary::PrintAFileInDict(string fileName)
{
	ifstream fin;
	fin.open(fileName.data());
	string importedWord;
	int rowCounter = 0;		// Used to make sure a max of 5 words per line
	
	if(!fin)
	{
		// Checks if the file exists
		cout << "File could not be found." << endl;
		return failure;
	}
	
	cout << "Words that begin with " << fileName[0] << ": " << endl << endl;
	
	while(fin >> importedWord)
	{
		/* 
			Imports the words one at a time and prints them in a specified table
				format
			Every 5 words, an end line is printed.
			This could have been implemented with a for loop.
		*/
		cout << setw(15) << left << importedWord << " | ";
		rowCounter++;
		
		if(rowCounter % 5 == 0)
			cout << endl;
	}
	cout << endl;
	
	return success;
}

/***************************************************************************
 * SpellChecking                                                           *
 *                                                                         *
 *  Compares each word in a given file with words in the dictionary and    *
 *  states which words are "misspelled" or not in the dictionary.          *
 ***************************************************************************/
bool Dictionary::SpellChecking(string fileName)
{
	ifstream fin;
	int totalWordsCounter = 0;	// Tracks number of misspelled words
	fin.open(fileName.data());
	string importedWord;
	
	// Checks if the file exists
	if(!fin)
	{
		
		cout << "File could not be found." << endl;
		return failure;
	}
	
	while(fin >> importedWord)
	{
		/* 
			Imports the words one at a time and checks if they're in the
				dictionary using SearchForWord
				
		*/
		if(!SearchForWord(importedWord))
		{
			cout << importedWord << endl;
			totalWordsCounter++;
		}
	}
	
	cout << endl << totalWordsCounter << " misspelled words found!" << endl;
	
	return success;
}

/***************************************************************************
 * InsertWordsIntoDict                                                     *
 *                                                                         *
 * Takes a file and imports each word into the dictionary                  *
 ***************************************************************************/
bool Dictionary::InsertWordsIntoDict(string fileName)
{
	ifstream fin;
	fin.open(fileName.data());
	string importedWord;
	
	if(!fin)
	{
		// Checks for file existence
		cout << "File could not be found." << endl;
		return failure;
	}
	
	while(!fin.eof())
	{
		/*
			While the entire file has not been imported, import the file one 
				word at a time.
			If the word isn't in the dictionary, add it.
			Otherwise, go onto the next word
		*/
		fin >> importedWord;
		if(!SearchForWord(importedWord))
			AddAWord(importedWord);
	}
	
	return success;
}

/***************************************************************************
 * fileNamer                                                               *
 *                                                                         *
 * Given a word, returns the correct file name for the word.               *
 * alpaca returns A.txt                                                    *
 ***************************************************************************/
string Dictionary::fileNamer(const string word)
{
	// Takes the first letter of the word, capitalizes it, and appends .txt
	return string(1, toupper(word[0])) + ".txt";
}

/***************************************************************************
 * ProcessTransactionFile                                                  *
 *                                                                         *
 * Given a file with instructions in the [Instruction] [word] format,      *
 * executes the instruction with the given parameter.                      *
 ***************************************************************************/
void Dictionary::ProcessTransactionFile()
{
	ifstream fin;
	fin.open("commands.txt");
	string commands, parameter;
	
	while(!fin.eof())
	{
		fin >> commands >> parameter;
		printDivider(commands, parameter);	// Prints a divider with the command
											// and parameter for visual clarity
		if(commands == "AddW")
		{
			// AddW - add a word to the dictionary.
			if(AddAWord(parameter))
				cout << "\"" << parameter << "\" added!" << endl << endl;
			else
				cout << "\"" << parameter << "\" not added." << endl << endl;
		}
		else if(commands == "DeleteW")
		{
			// DeleteW - deletes a word from the dictionary.
			if(DeleteAWord(parameter))
				cout << "\"" << parameter << "\" removed!" << endl << endl;
			else
				cout << "\"" << parameter << "\" not removed." << endl << endl;
		}
		else if(commands == "SearchW")
		{
			// SearchW - Checks if a word is already in the dictionary.
			if(SearchForWord(parameter))
				cout << "\"" << parameter << "\" found in the dictionary!"
					<< endl << endl;
			else 
				cout << "\"" << parameter << "\" is not in the dictionary." 
					<< endl << endl;
		}
		else if(commands == "PrintF")
		{
			// Printf - Prints an entire file (or all words starting with 
				// a given letter.
			PrintAFileInDict(parameter);
		}
		else if(commands == "SpellCheck")
		{		
			// SpellCheck - Check if words in a given file are in the dictionary
			cout << "The following words are misspelled: " << endl << endl;
			SpellChecking(parameter);
		}
		else if(commands == "InsertF")
		{
			// InsertWordsIntoDict - Import words of a file into the dictionary.
			if(InsertWordsIntoDict(parameter))
				cout << "Successful import of " << parameter << endl << endl;
			else
				cout << "Import was not successful." << endl << endl;
			
		}
		else
			cout << "Not a valid command! Check the source file. " << endl;
	}
}

/***************************************************************************
 * printDivider                                                            *
 *                                                                         *
 * Prints a visual separator that distinguishes each command. The divider  *
 * includes a given command and a word or file name being passed in with it*
 ***************************************************************************/
void Dictionary::printDivider(const string command, const string parameter)
{
		// Prints 35 dashes
		for(int i = 0; i < 35; i++)
			cout << "-";
		
		// Prints the command and the parameter given
		cout << setw(10) << right << command << " " 
			<< setw(10) << left << parameter;
			
		// Prints another 35 dashes	
		for(int i = 0; i < 35; i++)
			cout << "-";
		
		cout << endl << endl;
}

/***************************************************************************
 * printDivider                                                            *
 *                                                                         *
 * Returns a given word except in all lower case                           *
 ***************************************************************************/
string Dictionary::wordToLower(const string word)
{
	string newWord = "";
	
	for (int i = 0; i < word.length(); i++)
	{
		newWord += tolower(word[i]);
	}
	
	return newWord;
}

#endif

