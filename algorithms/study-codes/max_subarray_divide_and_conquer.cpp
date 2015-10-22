/* Problem: Maximum Subarray
 * Method: Divide and Conquer
 * Time complexity: O(n*logn)
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution
{
	public:
		int low, high, sum;
};

Solution findCrossingMaximumSubarray (int array[], int low, int mid, int high)
{
	int leftSum = INT_MIN, rightSum = INT_MIN;
	int sum = 0;
	int maxLeft = mid;
	for (int i = mid; i >= low; i--)
	{
		sum += array[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			maxLeft = i;
		}
	}
	sum = 0;
	int maxRight = mid+1;
	for (int i = mid+1; i <= high; i++)
	{
		sum += array[i];
		if (sum > rightSum)
		{
			rightSum = sum;
			maxRight = i;
		}
	}
	
	Solution sol;
	sol.low = maxLeft;
	sol.high = maxRight;
	sol.sum = leftSum + rightSum;
	return sol;
}

Solution findMaximumSubarray (int array[], int low, int high)
{
	if (low == high) // base case
	{
		Solution sol;
		sol.low = low, sol.high = high, sol.sum = array[low];
		return sol;
	}
	Solution left, right, cross;
	
	int mid = low + (high - low) / 2;
	
	left = findMaximumSubarray (array, low, mid);
	right = findMaximumSubarray (array, mid+1, high);
	cross = findCrossingMaximumSubarray (array, low, mid, high);
	
	if (left.sum >= right.sum && left.sum >= cross.sum)
		return left;
	else if (right.sum >= left.sum && right.sum >= cross.sum)
		return right;
	else
		return cross;
}

int main (void)
{
	int n;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	Solution sol = findMaximumSubarray (array, 0, n-1);
	cout << sol.low << " " << sol.high << " " << sol.sum << endl;
	return 0;
}
