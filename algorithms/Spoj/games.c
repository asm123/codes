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
		char avg [15];
		scanf ("%s", avg);
// 		printf ("%s\n", avg);
		int i = 0, flag = 0;
		long long int n = 0, d = 1;
		while (avg[i])
		{
// 			printf ("%c ", avg[i]);
			if (flag)
			  d *= 10;
			if (avg[i] == '.')
			  flag = 1;
			else
			  n = n * 10 + (avg[i] - '0');
			i++;
		}
		
		
// 		printf ("\n%lld %lld\n", n, d);
		if (n % d == 0)
		  printf ("1\n");
		else
		{
			int factor[8] = {2, 2, 2, 2, 5, 5, 5, 5};
			for (i = 0; i < 8; i++)
			{
				if (!(n % factor[i] || d % factor[i]))
				{
					n /= factor[i];
					d /= factor[i];
				}
			}
			printf ("%lld\n", d);
		}
	}
	return 0;
}