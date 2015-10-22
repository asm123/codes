#include <stdio.h>
#include <limits.h>

int main (void)
{
	int T;
	scanf ("%d", &T);
	while (T--)
	{
		int sum = 0, maxSum = -1000000000;
		int n, maxNum = 0;
		long long int maxCnt = 0, cnt = 1;
		scanf ("%d", &n);
		while (n--)
		{
			int num;
			scanf ("%d", &num);
			sum += num;
			
			if (sum - maxNum > maxSum)
			{
				maxSum = sum - maxNum;
				maxCnt = cnt;
			}
			else if (sum - maxNum == maxSum)
				maxCnt += cnt;
			
			if (sum < maxNum)
			{
				maxNum = sum;
				cnt = 1;
			}
			else if (sum == maxNum)
				cnt++;
		}
		printf ("%d %lld\n", maxSum, maxCnt);
	}
	return 0;
}
