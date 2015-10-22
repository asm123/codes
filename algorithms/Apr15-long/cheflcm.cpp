#include <iostream>
#include <cstdio>
#include <cmath>

int main (void)
{
	int len = 100009;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf ("%d", &N);
		len = ceil (sqrt(N));
		unsigned long long int sum = 0;
		for (int i = 1; i <= len; i++)
		{
			if (N % i)
				continue;
			else
			{
				int factor = N / i;
				if (factor < len)
					break;
				sum += i;
				if (i != factor)
					sum += factor;
			}
		}		
		printf ("%lld\n", sum);
	}
	
	return 0;
}
