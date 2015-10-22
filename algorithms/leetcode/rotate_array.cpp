#include <iostream>

using namespace std;

class Solution 
{
	private:
		void reverse(int nums[], int start, int end)
		{
			while (start < end)
			{
				int temp = nums[start];
				nums[start] = nums[end];
				nums[end] = temp;
				start++;
				end--;
			}
		}
	public:
		void rotate (int nums[], int n, int k) 
		{
			k = k % n;
			reverse (nums, 0, n-k-1);
			reverse (nums, n-k, n-1);
			reverse (nums, 0, n-1);
		}
};

int main (void)
{
	int a[3] = {1, 2, 3};
	Solution sol;
	sol.rotate(a, 3, 0);
	for (int i = 0; i < 3; i++)
		cout << a[i] << " ";
	cout << endl;
}
