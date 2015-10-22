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
	int num[1000001];
	memset (num, 0, sizeof (num));
	int max = 0;
	while (t--)
	{
		int n = read ();
		num[n]++;
		if (n > max)
			max = n;
	}
	
	for (int i = 0; i <= max; i++)
	{
		while (num[i]--)
		  printf ("%d\n", i);
	}
	
	return 0;
}