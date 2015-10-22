#include <iostream>
#include <stdio.h>

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
	int t = read ();
	while (t--)
	{
		int n = read ();
		int k = 0;
		for (int i = 0; i < n; i++)
		  k += read () / (i + 1);
		
		if (k % 2)
		  printf ("ALICE\n");
		else
		  printf ("BOB\n");
	}
	return 0;
}