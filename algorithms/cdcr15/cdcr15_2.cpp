#include <cstdio>
#include <cmath>

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
	int Q = read();
	while (Q--)
	{
		int x = read(), y = read(), z = read();
		printf ("%d\n", (int)ceil((x*z*1.0)/y )-1);
	}
	return 0;
}
