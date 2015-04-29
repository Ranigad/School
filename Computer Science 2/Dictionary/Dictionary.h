#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
using namespace std;
#define LETTERSOFTHEALPHABET 26	// Macro for numOfWordsInFile array size
class Dictionary
{
	private:
		/* Maximum number of words allowed in each file and in the entire
			dictionary*/
		const 	int maxWordsInDict;
		const	int maxWordsPerFile;
		
		// Total number of words in a file (0-25 for a-z) and dictionary
		int	totalWordsInDict;
		int	numOfWordsInFile[LETTERSOFTHEALPHABET];
		
		// Macros for true/false for readability
		static	bool failure;
		static	bool success;
		
		// Returns the file name for any given word
		string fileNamer(const string);	
		
		// Prints a divider for visual organization
		void printDivider(const string command, const string parameter);
		
		// Converts every letter in a word to lower case
		string wordToLower(const string);
	
	public:
		// Constructors
		Dictionary();
		Dictionary(int dictMaxWords, int fileMaxWords);
		~Dictionary();	// Destructor
		bool AddAWord(string word);	// Adds a word to the dictionary
		bool DeleteAWord(string word);	// Removes a word from the dictionary
		bool SearchForWord(string word);	// Checks if a word is in the dict.
		bool PrintAFileInDict(string filename);	// Prints all words in a file
		bool SpellChecking(string fileName);	// Checks if a given file has
												// any incorrectly spelled words
		bool InsertWordsIntoDict(string fileName);	// Imports words into the
													// dictionary from a file
		void ProcessTransactionFile();	// Follows instructions from a file
};

#endif


