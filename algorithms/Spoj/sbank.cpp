using namespace std;

#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>

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
		map <string, int> m;
		map <string, int>::iterator it;
		int n = read (), i;
		for (i = 0; i < n; i++)
		{
			char ac[35];
			gets (ac);
			m[(string)ac]++;
		}
		for (it = m.begin (); it != m.end (); it++)
		  printf ("%s %d\n", it->first.c_str (), it->second);
		if (t > 1)
		  printf ("\n");
	}
	return 0;
}