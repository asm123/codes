#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
	public:
		vector <int> plusOne (vector <int>& digits) 
		{
			vector <int> plusOne(digits.size(), 0);
			if (digits.back() <= 8)
			{
				digits.back()++;
				return digits;
			}
			int carry = 1;
			int i = plusOne.size()-1;
			for (vector <int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it ) 
			{
				int sum = *it + carry;
				plusOne[i] = sum % 10;
				carry = sum / 10; 
				i--;
			} 
			if (carry == 1);
			{
				cout << "Carry is 1" << endl;
				if (plusOne.front() <= 8)
					plusOne.front()++; 
				else
				{
					plusOne.front() = 0;
					plusOne.insert (plusOne.begin(), 1);
				}
			}
			return plusOne;
		}
};

int main (void)
{
	Solution sol;
	vector <int> digits;
	for (int i = 1; i < 10; i++)
		digits.push_back(i);
	vector <int> plusOne = sol.plusOne (digits);
	for (unsigned int i = 0; i < plusOne.size(); i++)
		cout << plusOne[i] << endl;
	
	return 0;
}

