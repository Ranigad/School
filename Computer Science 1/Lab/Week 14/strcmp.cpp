#include <iostream>
using namespace std;

//int myStrCmp(const char firstString[], const char secondString[]);
int myStrCmp2(const char firstString[], const char secondString[]);

int main()
{
	char string1[10];
	char string2[10];

	cout << "Enter the first string: ";
	cin >> string1;
	getchar();
	cout << "Enter the second string: ";
	cin >> string2;
	getchar();
	
//	cout << myStrCmp(string1, string2) << endl;
	cout << myStrCmp2(string1, string2) << endl;
	return 0;

}


/*int myStrCmp (const char firstString[], const char secondString[])
{
	int returnNum = 0;
	for (int i = 0; firstString[i] != '\0' || secondString[i] != '\0'; i++)
	{
		if (firstString[i] < secondString[i])
		{
			returnNum = -1;
			break;
		}
		else if (firstString[i] > secondString[i])
		{
			returnNum = 1;
			break;
		}
	}

	return returnNum;
}*/

int myStrCmp2 (const char firstString[], const char secondString[])
{
	int returnNum = 0;
	int i = 0;	
	while (firstString[i] == secondString[i] && (firstString[i] != '\0' || secondString[i] != '\0'))
		i++;
		
	if (firstString[i] < secondString[i])
		returnNum = -1;
	else if (firstString[i] > secondString[i])
		returnNum = 1;
		
	return returnNum;
}

