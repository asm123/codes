#include <cstdio>

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
	int  win[1000001] = {0};
	int K = read (), L = read ();
	
	win[0] = 0;
	for (int i = 1; i < 1000001; i++)
	{
		if (win[i-1] == 0)
			win[i] = 1;
		else if (i-K >= 0 && win[i-K] == 0)
			win[i] = 1;
		else if (i-L >= 0 && win[i-L] == 0)
			win[i] = 1;
	}
	int m = read ();
	while (m--)
	{
		int n = read ();
		if (win[n])
			printf ("A");
		else
			printf ("B");
	}
	printf ("\n");
	return 0;
}
