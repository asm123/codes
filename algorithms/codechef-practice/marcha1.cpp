#include <stdio.h>

bool is (int, int);

int n, notes[20];

inline int read ()
{
	char c;
	int x = 0;
		
	while ((c = getchar_unlocked ()) < 48);
	x += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  x = x * 10 + (c - '0');
	
	return x;
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		n = read ();
		int m = read ();
		for (int i = 0; i < n; i++)
		  notes[i] = read ();
		if (is(0, m))
		  printf ("Yes\n");
		else
		  printf ("No\n");
	}
  
	return 0;
}

bool is (int i, int m)
{
	if (m == 0)
	  return true;
	if (i >= n || m < 0)
	  return false;
	return (is (i + 1, m) || is (i + 1, m - notes[i]));
}