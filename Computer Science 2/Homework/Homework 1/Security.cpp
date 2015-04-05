/*
	Implementation file for the class Security
	Purpose: To encrypt any given input string through either a Caesar/Rotation
		or cryptogram method

*/

#ifndef SECURITY_CPP
#define SECURITY_CPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctype.h>
#include "Security.h"

	// Constructor
		// Initializes the input file name and output file name to a default
		// non value. Also initializes the key to the assignment one
	Security::Security()
	{
		inputFileName = "None Currently Set";
		outputFileName = "None Currently Set";
		key = "wyijkcuvdpqlzhtgabmxefonrs";
	}
	
	// Automates the steps for assignment 1
		// A method written to allow the graders to instantly fulfil the needs
		// of the assignment without multiple inputs
	void Security::assignment1()
	{
		inputFileName = "original.txt";	// Sets the initial input file
		setMessage();				// Imports the file into message.
		outputFileName = "encrypt1.txt";// Sets the output file
		encryptFileCaesar(13);		// Encrypts the message using rot13.
										// Also exports it to the given output
										
		inputFileName = "original.txt";
		message.clear();
		setMessage();
		outputFileName = "encrypt2.txt";// Sets the new output file
		encryptFileCrypto();		// Encrypts and exports message using crypto
		
		inputFileName = "encrypt1.txt";	// Sets the input as encrypted rot
		message.clear();			// Clears the message vector
		setMessage();				// Imports the new message from input file
		outputFileName = "decrypt1.txt";// Sets new output file
		decryptFileCaesar(13);		// Decrypts the rot13
		
		inputFileName = "encrypt2.txt";	// Sets the input as encrypted crypto
		message.clear();			// Clears the message vector
		setMessage();				// Imports the new message from input file
		outputFileName = "decrypt2.txt";// Sets new output file
		decryptFileCrypto();		// Decrypts the crypto
		
		// Message for user + more noticeability
		cout << endl << endl;
		cout << " ************************************************ " << endl;
		cout << " * " << setw(44)
			 << "Exit the program to view the resulting text" << " * ";

	}
	
	/************** Message Input/Output and Changing attributes **************/
	
	// setMessage
		// Imports the message into the message vector from the pre-set input
		// file.
	void Security::setMessage()
	{
		ifstream fin;	// Input file stream
		string word;	// Local variable to hold the imported word

		fin.open(inputFileName.data());
		while(fin >> word)	// While the filestream still has words to import
		{
			message.push_back(word);	// Pushes onto the message vector
		}
	}
	
	// setKey
		// Allows the user to the change the key
	void Security::setKey()
	{
		string newKey;	// Used to test if the key is valid before replacing key
		
		cout << "Include each letter of the alphabet once." << endl
			 << " No spaces or other special characters." << endl;
		cout << "Ex: bcdefghijklmnopqrstuvwxyza" << endl;
		cout << "Enter your new key: ";
		cin >> newKey;
		
		if(validKey(newKey))	// Checks if the new key is valid
			key = newKey;		//  and saves if it is
		else
		{
			cout << endl << endl;
			cout << " ************************************************ " << endl;
			cout << " * " << setw(44) << "Not a valid key!" << " * ";	
			// Otherwise gives message and returns to menu
		
		}
	}
		
	// setInputFileName	
		// Allows the user to the change the message source
	void Security::setInputFileName()
	{
		ifstream fin;	// Input file stream
		string userInput;	
		/* Uses a local string instead of directly writing to inputFileName
			in case user wants to exit without entering a new input file */
		
		cout << "What is the file name of the input source? " << endl
			 << "Enter q to exit: ";
		cin >> userInput;
		
		fin.open(userInput.data());
		
		/* Enters while loop if the user did not press q and the file doesn't
			exist */
		while(!fin && userInput.compare("q") != 0)	
		{
			fin.close();
			cout << "This file doesn't exist!" << endl << "Enter a file name: ";
			
			cin >> userInput;
			fin.open(userInput.data());
		}
		
		if(fin)	// Replaces the inputFileName if the file name does exist
			inputFileName = userInput;
		
		fin.close();
		
		message.clear();	// Clears message and sets message from new
		setMessage();			// Input file
	}	
	
	// setOutputFileName
		// Allows the user to change the output destination for the encryption
	void Security::setOutputFileName()
	{			
		cout << "What is the name of the file"
			<< " you want to output your message to? ";
		cin >> outputFileName;
	}
		
	// sendMessageToFile
		// Sends the message stored in vector encryptedMessage to the set 
		// output file.
	void Security::sendMessageToFile()
	{
		ofstream fout;	// Output file stream
		fout.open(outputFileName.data());

		for (int i = 0; i < encryptedMessage.size(); i++)
		{
			// Sends each word to file separated by a space.
			fout << encryptedMessage[i] << " ";
		}
		fout << endl;
		fout.close();
		
		encryptedMessage.clear();	// Clears encrypted message for next send.
	}

	
	/****************************** Encryptions ******************************/
		// Encrypts the vector message and sends the encrypted message to 
		// the vector encryptedMessage
		
		
		// Uses the caesar/rot method to encrypt message
	void Security::encryptFileCaesar(int shift)
	{
		string newWord;	// New word to manipulate and send to encrypted vector.
		char newLetter;	// Used to split up the replacement line so it wouldn't
						// go over the 80 character limit.
		
		for (int i = 0; i < message.size(); i++)
		{
			newWord = message[i];
			for (int j = 0; j < message[i].length(); j++)
			{
				/* 
				1. Takes the letter and applies the shift.
				2. Subtracts 'A' or 'a' to get a numerical representation
				of the letters (a = 0, b = 1)
				3. Modulus by 26 to take into account going past 'z' or 'Z' 
				4. Adds 'A' or 'a' to return to the correct letter
				*/
				if(isupper(message[i][j]))
				{
					newLetter = ((message[i][j] + shift - 'A') % 26) + 'A';
					newWord.replace(j, 1, 1, newLetter);
				}
				else if (islower(message[i][j]))
				{
					newLetter = ((message[i][j] + shift - 'a') % 26) + 'a';
					newWord.replace(j, 1, 1, newLetter);						
				}
			}
			encryptedMessage.push_back(newWord); // Saves the encrypted word
		}
		
		sendMessageToFile();	// Sends encrypted message to output file
	}

		// Uses the cryptogram method to encrypt method
	void Security::encryptFileCrypto()
	{
		string newWord;	// New word to manipulate and send to encrypted vector.
		
		for(int i = 0; i < message.size(); i++)
		{
			newWord = message[i];
			
			for (int j = 0; j < newWord.length(); j++)
			{			
			/* 
				1. Takes the word and subtracts 'A' or 'a to get a numerical 
				representation of the letter (a = 0, b = 1)
				2. Finds the corresponding index in the key 
				3. Replaces the old letter with the correct key letter
			*/
				if (isupper(newWord[j]))
				{
					// toupper allows for maintaining the capital letters.
					newWord.replace(j, 1, 1, toupper(key[newWord[j] -'A']));
				}
				else if (islower(message[i][j]))
				{
					newWord.replace(j, 1, 1, key[newWord[j] - 'a']);
				}
			}
			
			encryptedMessage.push_back(newWord);
		}
		
		sendMessageToFile();

	}
	
	
	/****************************** Decryptions ******************************/
		// Takes the message and applies either the caesar/cryptogram method
		// in reverse to decrypt it. Then saves it into encryptedMessage vector
		// and sends it to file.
		
		// Uses the caesar/rot method in reverse to decrypt Message.
	void Security::decryptFileCaesar(int shift)
	{
		string newWord; // New word to manipulate and send to encrypted vector.
		char newLetter; // Used to split up the replacement line so it wouldn't
						// go over the 80 character limit.
		
		for (int i = 0; i < message.size(); i++)
		{
			newWord = message[i];
			
			for (int j = 0; j < newWord.length(); j++)
			{		
				/* 
				1. Takes the letter and applies the shift.
				2. Subtracts 'A' or 'a' to get a numerical representation
				of the letters (a = 0, b = 1)
				3. Adds 26 to account for wrapping (might have shifted past 0)
				4. Modulus by 26 to account for wrapping
				5. Adds 'A' or 'a' to return to the correct letter
				
				This shifts in the opposite direction of the encrypt method
				*/
				if(isupper(newWord[j]))
				{
					newLetter = ((newWord[j] - shift - 'A' + 26) % 26) + 'A';
					newWord.replace(j, 1, 1, newLetter);
				}
				else if (islower(newWord[j]))
				{
					newLetter = ((newWord[j] - shift - 'a' + 26) % 26) + 'a';
					newWord.replace(j, 1, 1, newLetter);						
				}
			}
			
			encryptedMessage.push_back(newWord);
		}
		
		sendMessageToFile();
	}
		
		
		// Uses the cryptogram in reverse to decrypt Message
	void Security::decryptFileCrypto()
	{
		string newWord; // New word to manipulate and send to encrypted vector.

		for(int i = 0; i < message.size(); i++)
		{
			newWord = message[i];
			
			for (int j = 0; j < newWord.length(); j++)
			{
				/*
				With each character of each word
				1. Takes the character and finds its location (index) in 
					the key string. This is the numerical representation of
					the letter (a = 0... z = 25)
				2. Add 'a' or 'A' to the index to reconvert it to a letter
				*/
				
				if (isupper(newWord[j]))
				{
					/* Since we kept upper case in the encryption but the
					key is all lowercase, we must first convert any upper
					case letters to lower case */
					newWord.replace(j, 1, 1, 
						key.find(tolower(newWord[j])) + 'A');
				}
				else if (islower(newWord[j]))
				{
					newWord.replace(j, 1, 1, key.find(newWord[j]) + 'a');
				}
			}
			
			encryptedMessage.push_back(newWord);
		}
		
		sendMessageToFile();

	}
		
	/***************************** Helper Methods *****************************/
	
	// validKey	
		// Checks if the given key is valid or not.
		// 1. All letters in the alphabet are present at most once
		// 2. There are 26 letters.
	bool Security::validKey(string key)
	{
		
		bool alphabet[26] = {false};	// Flags to check if a letter of the 
										// alphabet has previously occured.
		bool valid = true;	// Flag for whether the key is valid or not
		int letterIndex;	// Index 
		
		for(int i = 0; i < 26; i++)
		{
			/* For each letter in the key...
			1. letterIndex is the numerical representation of any given number
				(0 - 25)
			2. Convert the letter to the corresponding index and flip the flag
				in the alphabet boolean array
			3. If the flag is already flipped, the letter has appeared twice
				and the key is invalid.
			*/
			
			letterIndex = tolower(key[i]) - 'a'; // #1
			
			if(alphabet[letterIndex])
				valid = false;	// #3
			else
				alphabet[letterIndex] = true; // #2
		}
		
		return valid;
	}
	
	//printMenu
		// Prints the menu for the class.
	void Security::printMenu()
	{		
		// Menu
		cout << endl;
		
		cout << " ************************************************ " << endl;
		
		// Informs the user of the current input file, output file, and key 
		cout << " * " << setw(15) << left << "Input" << " | "
			 << setw(26) << left << inputFileName << " * " << endl
			 
			 << " * " << setw(15) << left << "Output" << " | "
			 << setw(26) << left << outputFileName << " * " << endl
			 
			 << " * " << setw(15) << left << "Key: " << " | "
			 << setw(26) << left << key << " * " << endl;
		
		// Prints the actual menu.
		cout << " * -------------------------------------------- * " << endl
			 << " * 0 - Preprogrammed Assignment 1               * " << endl
			 << " * 1 - Encrypt using Rot/Caesar                 * " << endl
			 << " * 2 - Encrypt using Cryptogram                 * " << endl
			 << " * 3 - Decrypt using Rot/Caesar                 * " << endl
			 << " * 4 - Decrypt using Cryptogram                 * " << endl
			 << " * -------------------------------------------- * " << endl
			 << " * m - Change Message Source                    * " << endl
			 << " * o - Change Output Destination                * " << endl
			 << " * k - Change Key                               * " << endl
			 << " * q - Exit Program                             * " << endl
			 << " ************************************************ " << endl;
	}
		

#endif

