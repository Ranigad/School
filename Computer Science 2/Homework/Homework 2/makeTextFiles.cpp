#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename;
	ofstream fout;
	for(int i = 'A'; i <= 'Z'; i++)
	{
		filename = string(1, (char) i) + ".txt";
		fout.open(filename.data());
		fout << "";
		fout.close();
	}

return 0;
}
