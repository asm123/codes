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
		unsigned int min_1 = 10000000;
		unsigned int min_2 = 10000000;
		for (int i = 0; i < N; i++)
		{
			unsigned int a = read();
			if (a <= min_1)
			{
				min_2 = min_1;
				min_1 = a;
			}
			else if (a <= min_2)
				min_2 = a;
		}
		printf ("%u\n", min_1 + min_2);
	}
}
