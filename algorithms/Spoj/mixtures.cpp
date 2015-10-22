/*
 * User: asm149
 * Problem: MIXTURES
 * Algorithm: DP - Matrix Chain Multiplication O(n^3)
 * */


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

int min (int a, int b) { return a < b ? a : b; }

int minSmoke (int color[], int n)
{
	int smoke[n][n], mix[n][n];
	smoke[0][0] = 0;
	mix[0][0] = color[0];
	for (int i = 1; i < n; i++)
	{
		smoke[i][i] = 0;
		mix[i][i] = color[i];
		mix[i-1][i] = (color[i-1] + color[i]) % 100;
		smoke[i-1][i] = color[i-1] * color[i];
	}
	
	for (int l = 2; l <= n; l++) // length of the chain
	{
		for (int i = 0; i <= n-l; i++) // beginning of the chain
		{
			int j = i+l-1; // end of the chain
			smoke[i][j] = 100000000;
			for (int k = i; k < j; k++) // mix point
			{
				int temp = smoke[i][k] + smoke[k+1][j] + mix[i][k] * mix[k+1][j];
				if (smoke[i][j] > temp)
				{
					smoke[i][j] = temp;
					mix[i][j] = (mix[i][k] + mix[k+1][j]) % 100;
				}
			}
		}
	}
	return smoke[0][n-1];
}

int main (void)
{
	int n;
	while (scanf ("%d", &n) == 1)
	{
		int color[n];
		for (int i = 0; i < n; i++)
			color[i] = read ();
		printf ("%d\n", minSmoke (color, n));
	}
}
