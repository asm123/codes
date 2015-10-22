#include <stdio.h>

inline int read ()
{
	char c;
	int x = 0;
		
	while ((c = getchar_unlocked ()) < 48);
	x += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  x = x * 10 + (c - '0');
	
	return x;
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		int n = read ();
		if (n % 2)
		  printf ("BOB\n");
		else
		  printf ("ALICE\n");
	}
	return 0;
}