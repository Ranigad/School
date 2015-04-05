/*   Name: Charles Li
     Date: 
	 Class: CS
	 Description: 
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int ROWSIZE = 5;
const int COLUMNSIZE = 5;

void initArray(char [][COLUMNSIZE]);
void buryTreasure(int&, int&);
int dig(int, int, char [][COLUMNSIZE]);
void checkMap(char map[][COLUMNSIZE]);
bool checkDigSite(int xDig, int yDig);

int main()
{
	char map[ROWSIZE][COLUMNSIZE];
	int x, y, tries = 0;
	
	initArray(map);
	buryTreasure(x, y);
	
	while (tries == 0)
	{
		tries = dig(x, y, map);
	}
		
	cout << "It took ye " << tries << " tries to find the treasure!" << endl;
	
return 0;


}

void initArray(char theArray[][COLUMNSIZE])
{
	for (int rowNum = 0; rowNum < ROWSIZE; rowNum++) {
		for (int colNum = 0; colNum < COLUMNSIZE; colNum++) {
			theArray[rowNum][colNum] = 'o';
			}
		}
	return;
}

void buryTreasure(int& xPos, int& yPos)
{
	char notTreasure;
	do {
	cout << "Where would you like to bury the treasure?" << endl << "Enter a coordinate within between 1,1 and 5,5: ";
	cin >> xPos >> notTreasure >> yPos;
	} while(!checkDigSite(xPos, yPos));
	return;
}

int dig(int xPos, int yPos, char map[ROWSIZE][COLUMNSIZE])
{
	int xDig, yDig, tries = 0;
	char trash;
	
	while (xDig != xPos && yDig != yPos) {
	checkMap(map);
	cout << endl << "Where would you like to dig?" << endl << "Enter a coordinate (i.e. 6,7): ";
	cin >> xDig >> trash >> yDig;
	if (!checkDigSite(xDig, yDig)) {
	cout << "That ain't on the map lad!" << endl; 
	continue;
		}
	if (xDig == xPos && yDig == yPos) cout << "Avast, ye have found the treasure!" << endl;
	else {
		map[xDig - 1][yDig - 1] = 'x';
		cout << "Nice try matey, let's keep digging" << endl;
		tries++;
		}
}
	return tries;
}

void checkMap(char map[ROWSIZE][COLUMNSIZE])
{
	for (int row = 0; row < ROWSIZE; row++) {
		cout << endl;
		for (int col = 0; col < COLUMNSIZE; col++) {
			cout << setw(2) << map[row][col] << " ";
			}
		}
		
	cout << endl;
	return;
}
	
bool checkDigSite(int xDig, int yDig)
{
if ((xDig >= 1 && xDig <= 5) && (yDig >= 1 && yDig <= 5) ) return true;
return false;
}
	