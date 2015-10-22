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
	char bit[1000000];
	int t = 1;
	while (scanf ("%s", bit) != EOF)
	{
		int i, count = 0, flag = 0;
		i = 0;
		while (bit[i])
		{
			if (bit[i] == '1' && !flag)
			{
				count++;
				flag = 1;
			}
			else if (bit[i] == '0' && flag)
			{
				count++;
				flag = 0;
			}
			i++;
		}
		printf ("Game #%d: %d\n", t++, count);
	}
	
	return 0;
}