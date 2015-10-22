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
		char c;
		scanf ("%c", &c);
		if (c == '0')
		  printf ("Airborne wins.\n");
		else
		  printf ("Pagfloyd wins.\n");
	}
	
	return 0;
}