using namespace std;

#include <stdio.h>
#include <map>

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
	if (a == 0)
	  return b;
	while (b)
	{
		if (a > b)
		  a -= b;
		else
		  b -= a;
	}
	return a;
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		int n = read (), i;
		long long int sum = 0;
		for (i = 1; i <= n; i++)
		  sum += ((i * n) / gcd (i, n));
		printf ("%lld\n", sum);
	}

	return 0;
}