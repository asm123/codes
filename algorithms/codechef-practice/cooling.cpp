using namespace std;

#include <stdio.h>
#include <algorithm>

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
		int n = read (), count = 0;
		int pie[n], rack[n];
		for (int i = 0; i < n; i++)
		  pie[i] = read ();
		for (int i = 0; i < n; i++)
		  rack[i] = read ();
		sort (pie, pie + n);
		sort (rack, rack + n);
		int i = 0, j = 0;
		while (i < n && j < n)
		{
			if (rack[j] < pie[i])
			{
				j++;
			}
			else if (rack[j] >= pie[i])
			{
				j++;
				count++;
				i++;
			}
		}
		printf ("%d\n", count);
		
	}
	return 0;
}