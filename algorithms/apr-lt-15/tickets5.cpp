#include <iostream>
 
using namespace std;
 
int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		string code;
		cin >> code;
		if (code.size() == 1)
			cout << "NO" << endl;
		else if (code.size() == 2)
		{
			if (code[0] == code[1])
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
		else
		{
			char c1 = code[0];
			char c2 = code[1]
			for (int i = 2; i < code.size(); i++)
			{
				if (code[i] == code[i-2])
					continue;
			}
		}
		
	}
	
	return 0;
}
