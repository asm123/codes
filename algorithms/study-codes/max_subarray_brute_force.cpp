/* Problem: Maximum Subarray
 * Method: Brute force
 * Time complexity: O(n^2)
 */  

#include <iostream>
#include <climits>

using namespace std;

class Solution
{
	public:
		int low, high, sum;
};

Solution findMaximumSubarray (int array[], int low, int high)
{
	Solution sol;
	sol.low = low;
	sol.high = low;
	sol.sum = INT_MIN;
	
	for (int i = low; i <= high; i++)
	{
		int sum = 0;
		for (int j = i; j <= high; j++)
		{
			sum += array[j];
			if (sum > sol.sum)
			{
				sol.sum = sum;
				sol.low = i;
				sol.high = j;
			}
		}
	}
	return sol;
}

int main (void)
{
	int n;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	Solution sol = findMaximumSubarray(array, 0, n-1);
	cout << sol.low << " " << sol.high << " " << sol.sum << endl;
	return 0;
}
