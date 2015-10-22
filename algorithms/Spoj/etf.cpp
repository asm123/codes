/*
 * User: asm149
 * Problem: ETF
 * Algorithm: Euler's Totient Function
 * n = p1.p2...pk
 * fi (n) = n (1 - 1/p1)(1 - 1/p2)...(1 - 1/pk)
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

int fi (int n)
{
	int result = n;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0) // factor
			result -= result / i;
		while (n % i == 0)
			n /= i;
	}
	if (n > 1)
		result -= result / n;
	return result;
}

int main (void)
{
	int T = read ();
	while (T--)
	{
		int n = read ();
		printf ("%d\n", fi (n));
	}
}
