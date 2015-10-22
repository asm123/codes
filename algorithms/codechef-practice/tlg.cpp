using namespace std;

#include <iostream>
#include <stdio.h>

inline int read ()
{
	register int n = 0, d;
	while ((d = getchar()) >= '0') 
	  n = (n << 3) + (n << 1) + (d - '0');
	return n;
}

int main (void)
{
	int n = read ();
	int sum_s = 0, sum_t = 0, max = 0, winner;
	for (int i = 0; i < n; i++)
	{
		sum_s += read ();
		sum_t += read ();
		if (sum_s > sum_t)
		{
			if (max < sum_s - sum_t)
			{
				max = sum_s - sum_t;
				winner = 1; 
			}
		}
		else if (sum_s < sum_t)
		{
			if (max < sum_t - sum_s)
			{
				max = sum_t - sum_s;
				winner = 2; 
			}
		}
	}
	
	printf ("%d %d\n", winner, max);
	
	return 0;
}