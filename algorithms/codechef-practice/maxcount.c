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
		int n = read (), i;
		int num[10001], max = 0, index = 0;
		for (i = 0; i < 10001; i++)
		  num[i] = 0;
		for (i = 0; i < n; i++)
		{
			int x = read ();
			num[x]++;
			if (num[x] > max)
			{
				max = num[x];
				index = x;
			}
			else if (num[x] == max && x < index)
			  index = x;
		}
		printf ("%d %d\n", index, num[index]);
	}
	return 0;
}