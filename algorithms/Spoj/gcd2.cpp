/*
 * User: asm149
 * Problem: GCD2
 * Algorithm: Euclid's Algo and integer operations using strings
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

int gcd (int a, int b)
{
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

void gcd2 (int a, char b[])
{
	if (a == 0)
		printf ("%s\n", b);
	else
	{
		int i = 0, num = 0;
		while (b[i])
		{
			num = (num*10 + (b[i]-'0')) % a;
			i++;
		}
		printf ("%d\n", gcd (a, num));
	}
}

int main (void)
{
	int T = read ();
	while (T--)
	{
		int A = read ();
		char B[251];
		scanf ("%s", B);
		gcd2 (A, B);
	}
}
