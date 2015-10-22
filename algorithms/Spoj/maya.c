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
	int power[7] = {1, 20, 360, 7200, 144000, 2880000, 57600000};
	while (1)
	{
		int n = read ();
		if (n == 0)
		  break;
		char digit[n][100];
		int num = 0, i, j;
		for (i = n-1; i >= 0; i--)
		  gets (digit[i]);
		for (i = 0; i < n; i++)
		{
			if (digit[i][0] == 'S')
			  continue;
			int d = 0;
			for (j = 0; digit[i][j]; j++)
			{
				if (digit[i][j] == '.')
				  d++;
				else if (digit[i][j] == '-')
				  d += 5;
			}
			num += d * power[i];
		}
		printf ("%d\n", num);
	}
  
	return 0;
}