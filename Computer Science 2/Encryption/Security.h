/*
	Header file for the Security class definition.
*/

#ifndef SECURITY_H
#define SECURITY_H

#include <vector>
#include <string>
using namespace std;

class Security{
		
	private: 
		vector<string> message;	// The message imported from the file
		vector<string> encryptedMessage;	// The manipulated message.
		string inputFileName;	// Name of the input file. Where the message is.
		string outputFileName;	// Destination of the manipulated message.
		string key;	// Key for the cryptogram.
		
		bool validKey(string);	// Checks if the key given is valid or not.
		
	public:
		Security();	// Constructor. 
		void setMessage();	// Fills the message vector with data from a file
		void setInputFileName(); // Sets the name of the input file
		void setOutputFileName();// Sets the name of the output file
		void setKey(); 	// Sets a new key;
		void sendMessageToFile();	// Output encryptedMessage into a given file
		void encryptFileCaesar(int);	// Does the "rot" or Caesar encryption
		void encryptFileCrypto();	// Encrypts the message using a given key
		void decryptFileCaesar(int);	// Decodes a message encrypted using the
										// "rot" or Caesar method
		void decryptFileCrypto(); // Decrypts a message encrypted using 
								  // the cryptogram and key method
		void assignment1();	// Completes assignment1 without inputs from user
		void printMenu(); // prints the Menu

};


#endif

