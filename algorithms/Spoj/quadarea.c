#include <stdio.h>
#include <math.h>

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
		double a, b, c, d, s;
		scanf ("%lf%lf%lf%lf", &a, &b, &c, &d);
		s = (a + b + c + d) / 2;
		printf ("%0.2lf\n", sqrt ((s - a) * (s - b) * (s - c) * (s - d)));
	}
	return 0;
}