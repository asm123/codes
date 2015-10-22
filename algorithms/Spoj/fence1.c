#include <stdio.h>
#define PI 3.141592653589793

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
	int l;
	while ((l = read ()))
	{
		printf ("%.2f\n", (l * l) / (2 * PI));
	}
	return 0;
}