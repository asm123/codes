#include <stdio.h>

int rev (int n)
{
	int revnum = 0;
	while (n > 0)
	{
		revnum = revnum * 10 + n % 10;
		n /= 10;
	}
	return revnum;
}

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
		int n1 = read ();
		int n2 = read ();
		printf ("%d\n", rev (rev (n1) + rev (n2)));
	}
	return 0;
}