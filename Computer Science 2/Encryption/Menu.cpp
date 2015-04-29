#ifndef MENU_CPP
#define MENU_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include "Menu.h"

		Menu::Menu(){
		}
		
		void Menu::setSelection() {
			char menuChoice;
			
			cout << "Choose an option: ";
			cin >> menuChoice;
			
			while(selection < '1' || selection > '5'){
				cout << "Invalid selection! Please try again: ";
				selection;
			}
		}
		
		char Menu::getSelection() {
			return selection;
		}
		
		void Menu::printFirstPage(string inputName, string outputName) {
			cout << " *************************************** " << endl;
			
			cout << " * " << setw(15) << left << "Input" << " | "
				 << setw(15) << right << "Key" << " * " << endl
				 << " * " << setw(15) << left << inputName << " | "
				 << setw(15) << right << key << " * " << endl;
				 
			cout << " * ----------------------------------- * " << endl
				 << " * 1 - Encryption                      * " << endl
				 << " * 2 - Decryption                      * " << endl
				 << " * 3 - Change Message Source           * " << endl
				 << " * 4 - Change Key						* " << endl
				 << " * 5 - Exit Program                    * " << endl
				 << " *************************************** " << endl;
		}
		
		void Menu::printSecondPage(){
			cout << " *************************************** " << endl
				 << " * 1 - Caesar / Rotation Method        * " << endl
				 << " * 2 - Cryptogram Method               * " << endl
				 << " *************************************** " << endl;
		}

#endif

