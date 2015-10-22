#include <iostream>
#include <cstdio>
using namespace std;

inline int read ()
{
	char c;
	int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

long long int maxWeight (int n, int cost[], int weight[], int k)
{
	int maxWt = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		int cst = 0, wt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				cst += cost[j];
				wt += weight[j];
			}
			if (cst <= k && maxWt < wt)
				maxWt = wt;
		}
	}
	return maxWt;
}

int main (void)
{
	int T = read ();
	while (T--)
	{
		int n = read (), k = read ();
		int cost[n], weight[n];
		for (int i = 0; i < n; i++)
		{
			cost[i] = read ();
			weight[i] = read ();
		}
		printf ("%lld\n", maxWeight (n, cost, weight, k));
	}
	return 0;
}
