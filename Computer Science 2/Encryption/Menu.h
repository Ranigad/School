#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class Menu{
	
	private: 
		bool secondPage;
		int selection;
		void printFirstPage(string inputName, string outputName);
		void printSecondPage();
		
	public:
		Menu();
		void setSelection();
		char getSelection();
		void printMenu();

};

#endif

