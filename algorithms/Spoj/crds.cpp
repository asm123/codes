/*
 * User: asm149
 * Problem: CRDS
 * Algorithm: Mathematics
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

int main (void)
{
	int T = read ();
	while (T--)
	{
		int n = read ();
		printf ("%lld\n", ((long long)n * (3*n + 1) / 2) % 1000007);
	}
}
