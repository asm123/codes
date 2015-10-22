#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution 
{
	private:
		string toString(int n)
		{
			char temp[21];
			sprintf (temp, "%d", n);
			return temp;
		}
	
	public:
		string countAndSay (int n) 
		{
			if (n == 1)
				return "1";
			
			string nStr = "1";
			n--;
			while (n--)
			{
				string result;
				int count = 0;
				char prev;
				for (unsigned int i = 0; i < nStr.length(); i++)
				{
					if (i == 0)
					{
						prev = nStr[i];
						count++;
					}
					else
					{
						if (nStr[i] == prev)
							count++;
						else
						{
							result += toString(count) + prev;
							count = 1;
							prev = nStr[i];
						}
					}
				}
				result += toString(count) + prev;
				nStr = result;
			}
			return nStr;
		}
};

int main (void)
{
	int x;
	cin >> x;
	Solution sol;
	cout << sol.countAndSay(x) << endl;
	return 0;
}
