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
	int n = read (), count = 0, a[1000];
	memset (a, 0, sizeof (a));
	while (1)
	{
		int temp = 0;
		count++;
		while (n > 0)
		{
			temp += (n % 10) * (n % 10);
			n /= 10;
		}
		if (temp == 1)
		{
			printf ("%d\n", count);
			break;
		}
		if (a[temp])
		{
			printf ("-1\n");
			break;
		}
		a[temp] = 1;
		n = temp;
	}
	return 0;
}
