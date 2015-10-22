#include <cstdio>
#include <algorithm>
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

bool findTriplet (int A[], int N, int P)
{
	int low, high;
	for (int i = 0; i < N-2; i++)
	{
		low = i + 1;
		high = N - 1;
		while (low < high)
		{
			if (A[i] + A[low] + A[high] == P)
				return true;
			else if (A[i] + A[low] + A[high] < P)
				low++;
			else
				high--;
		}
	}
	return false;
}

int main (void)
{
	int T = read ();
	while (T--)
	{
		int N = read ();
		int A[N];
		for (int i = 0; i < N; i++)
			A[i] = read ();
		int P = read ();
		sort (A, A+N);
		if (findTriplet (A, N, P))
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	
	return 0;
}
