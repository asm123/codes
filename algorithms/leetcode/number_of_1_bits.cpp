#include <iostream>

using namespace std;

class Solution 
{
	public:
		int hammingWeight (int n) 
		{
			int count = 0;
			while (n)
			{
				count += n & 1;
				n >>= 1;
			}
			return count;
		}
};

int main (void)
{
	int n;
	cin >> n;
	Solution sol;
	cout << sol.hammingWeight(11) << endl;
	return 0;
}
