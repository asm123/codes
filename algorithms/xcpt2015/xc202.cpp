#include <cstdio>

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
	int T = read();
	while (T--)
	{
		int N = read();
		int pos, max = 0;
		for (int i = 1; i <= N; i++)
		{
			int x = read();
			if (x >= max)
			{
				max = x;
				pos = i;
			}
		}
		printf ("%d\n", pos);
	}
	return 0;
}
