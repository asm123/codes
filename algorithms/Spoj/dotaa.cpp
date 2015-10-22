#include <iostream>
#include <cstdio>

using namespace std;

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
		int n = read (), m = read (), D = read (), count = 0;
		int heroes[n];
		for (int i = 0; i < n; i++)
		{
			heroes[i] = read ();
			while (heroes[i] > D)
			{
				heroes[i] -= D;
				count++;
			}
		}
		if (count >= m)
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}
