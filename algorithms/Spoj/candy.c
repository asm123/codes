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
	while (1)
	{
		int n;
		scanf ("%d", &n);
		if (n == -1)
		  break;
		int i, packet[n], sum = 0, each = 0;
		for (i = 0; i < n; i++)
		{
			packet[i] = read ();
			sum += packet[i];
		}
		if (sum % n != 0)
		  printf ("-1\n");
		else
		{
			each = sum / n;
			sum = 0;
			for (i = 0; i < n; i++)
			{
				if (packet[i] < each)
				  sum += each - packet[i];
			}
			printf ("%d\n", sum);
		}
	}
	return 0;
}