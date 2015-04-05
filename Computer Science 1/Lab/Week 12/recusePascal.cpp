#include <iostream>
using namespace std;

int pascal(int, int);
void showPascal(int);

int main()
{
    showPascal(3);
    return 0;
}


void showPascal(int row)
{
int printNum;
for(int i = row; i>=1;i--)
{
	for(int j = 1; j <= row; j++)
	{
		printNum = pascal(i,j);
		if (printNum != 0)
			cout << printNum;
	}
	
	cout << endl;
}
}


int pascal(int row,int col)
{
    int temp;

    if(col == 0) return 0;

    if (row == 1)    //anchor
    {
        return 1;
    }
    if (row == 2)    //anchor
    {
        return 1;
    }
    else            //recursion
    {
        for (int i=row;i>=1;i--)
        {
            for (int j=1;j<=row;j++)
            {
                return pascal(i-1,j-1)+pascal(i-1,j);
            }
        }
    }
}