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
		int a[2002] = {0};
		int n = read (), half = n / 2, i, pos = 0, flag = 0;
		for (i = 0; i < n; i++)
		{
			int j = read ();
			a[j + 1000]++;
			if (a[j + 1000] > half)
			{
				pos = j;
				flag = 1;
			}
		}
		if (!flag)
		  printf ("NO\n");
		else
		  printf ("YES %d\n", pos);
	}
	return 0;
}