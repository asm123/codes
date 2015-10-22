using namespace std;

#include <iostream>
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
		int n = read ();
		if (n == 0)
		  break;
		int perm[n + 1];
		int flag = 0;
		for (int i = 1; i <= n; i++)
		  perm[i] = read ();
		
		for (int i = 1; i <= n; i++)
		{
			if (perm[perm[i]] != i)
			{
				flag = 1;
				break;
			}
		}
		
		if (flag)
		  printf ("not ambiguous\n");
		else
		  printf ("ambiguous\n");
	}
}