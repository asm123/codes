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

int min (int a, int b) { return (a < b) ? a : b; }

int abs (int x) { return (x < 0) ? -x : x; }

int main (void)
{
	int T = read();
	while (T--)
	{
		int a = read();
		int A[a];
		for (int i = 0; i < a; i++)
			A[i] = read();
		int b = read();
		int B[b];
		for (int i = 0; i < b; i++)
			B[i] = read();
		int minDiff = 10000000;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				minDiff = min (minDiff, abs(A[i]-B[j]));
			}
		}
		printf ("%d\n", minDiff);		
	}
	return 0;
}
