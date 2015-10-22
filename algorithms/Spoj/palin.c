#include <stdio.h>
#include <string.h>

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
		char k[1000002];
		scanf ("%s", k);
		int len = strlen (k), flag = 0, i;
		for (i = 0; i < len; i++)
		{
			if (k[i] != '9')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf ("1");
			for (i = 1; i < len; i++)
			  printf ("0");
			printf ("1\n");
		}
		else
		{
			flag = 0;
			for (i = 0; i < len/2; i++)
			{
				if (k[i] > k[len - i - 1])
				  flag = -1;
				else if (k[i] < k[len - i - 1])
				  flag = 1;
				k[len - i - 1] = k[i];
			}
			if (flag == 0 || flag == 1)
			{
				int j = 0, mid;
				if (len % 2 == 0)
				  mid = len / 2 - 1;
				else
				  mid = len / 2;
				while (k[mid - j] == '9')
				{
					k[mid - j] = k[len - 1 - mid + j] = '0';
					j++;
				}
				k[mid - j]++;
				k[len - 1 - mid + j] = k[mid - j];
			}
			printf ("%s\n", k);
		}
	}
	return 0;
}