#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int newLineCounter = 0;

for (int i = 33; i <= 127; i++)
{cout << setw(2) << left << (char)i;
newLineCounter++;

if (newLineCounter%16 == 0)
{cout << endl;}
}

cout << endl; 

return 0;

}

