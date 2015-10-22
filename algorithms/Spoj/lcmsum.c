#include <stdio.h>
#define max 1000001

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
	int pfactor[max], lcm[max], i, j;
	for (i = 0; i < max; i++)
	  pfactor[i] = i;
	for (i = 2; i < max; i++)
	{
		if (pfactor[i] == 1)
		{
			for (j = i << 1; j < max; j += i)
			  if (pfactor[j] == j)
			    pfactor[j] = i;
		}
	}
	      
  
	int t = read ();
	while (t--)
	{
		int n = read (), i;
		
	}

	return 0;
}