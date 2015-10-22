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

int getCount (int A[], int N, int K)
{
	
}

int main (void)
{
	int N = read ();
	int A[N];
	for (int i = 0; i < N; i++)
		A[i] = read ();
	int Q = read ();
	while (Q--)
	{
		int K = read ();
		printf ("%d\n", getCount (A, N, K));
	}
	
	return 0;
}
