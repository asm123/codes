#include <cstdio>
#include <cmath>
using namespace std;

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
	int T = read ();
	while (T--)
	{
		int a = read (), b = read ();
		if (a == b)
			printf ("0\n");
		else
		{
			int sa = sqrt (a), sb = sqrt (b);
			int aNd, xOr;
			aNd = xOr = (sa+1) * (sa+1) - sa*sa;
			for (int i = sa+1; i < sb; i++)
			{
				int diff = (i+1) * (i+1) - i*i;
				aNd &= diff;
				xOr ^= diff;
			}
			printf ("%d\n", aNd & xOr);
		}
	}
	
	return 0;
}

