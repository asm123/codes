#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
	public:
		unsigned int reverseBits (unsigned int n)
		{
			/*
			int binary[32] = {0};
			
			int i = 0;
			while (n)
			{
				binary[i] = n % 2;
				n /= 2;
				i++;
			}
			unsigned int rev = 0;
			for (i = 0; i < 32; i++)
				rev += binary[i] * pow (2, 32-i-1);
			return rev;
			*/
			
			// space-optimized
			unsigned int rev = 0;
			
			for (int i = 0; i < 32; i++)
			{
				if ((n & (1 << i)))
					rev |= 1 << (31 - i);
			}
			return rev;
		}
};

int main (void)
{
	unsigned int x;
	cin >> x;
	Solution sol;
	cout << sol.reverseBits(x) << endl;
	return 0;
}
