using namespace std;

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
		int n = read ();
		int m = read ();
		int job[n + 1];
		for (int i = 1; i <= n; i++)
		  job[i] = 0;
		for (int i = 0; i < m; i++)
		  job[read ()] = 1;
		int turn = 0;
		for (int i = 1; i <= n; i++)
		{
			if (job[i] != 1)
			{
				if (turn % 2 == 0)
				{
					printf ("%d ", i);
					job[i] = 1;
				}
				turn++;
			}
		}
		printf ("\n");
		for (int i = 1; i <=n ; i++)
		{
			if (job[i] == 0)
			  printf ("%d ", i);
		}
		printf ("\n");
	}
	return 0;
}