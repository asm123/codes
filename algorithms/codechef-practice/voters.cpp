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
	char id[1000001]; // To reduce memory
	int count = 0, max = 0;
	for (int i = 1; i <= 1000000; i++)
	  id[0] = 0;
	
	int n = read () + read () + read ();
	while (n--)
	{
		int x = read ();
		id[x]++;
		if (id[x] == 2)
		  count++;
		if (x > max)
		  max = x;
	}
	
	printf ("%d\n", count);
	
	for (int i = 1; i <= max; i++)
	{
		if (id[i] > 1)
		  printf ("%d\n", i);
	}
	
	return 0;  
}

