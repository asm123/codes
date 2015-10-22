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
		char str[] = "abcdefghijklmnopqrstuvwxyz";
		char rev[] = "zyxwvutsrqponmlkjihgfedcba";
		int k = read ();
		int m = k / 25;
		int n = k % 25;
		if (n)
		{
			while (n >= 0)
			  printf ("%c", str[n--]);
		}
		while (m--)
		  printf ("%s", rev);
		printf ("\n");
		
	}
	return 0;
}