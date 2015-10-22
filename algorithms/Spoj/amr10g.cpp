#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int min (int x, int y) { return y ^ ((x ^ y) & -(x < y)); }

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

int compare (const void *a, const void *b) 
{
	return (*(int *)a - *(int *)b);
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		int N = read (), K = read ();
		int ht[N];
		for (int i = 0; i < N; i++)
			ht[i] = read ();
		int diff = INT_MAX;;
		if (K == 1)
			diff = 0;
		else
		{
			qsort (ht, N, sizeof (int), compare);
			if (K == N)
				diff = ht[N-1] - ht[0];
			else
			{
				for (int i = 0; i <= N-K; i++)
					diff = min (diff, ht[i+K-1] - ht[i]);
			}
		}
		printf ("%d\n", diff);
	}
	return 0;
}
