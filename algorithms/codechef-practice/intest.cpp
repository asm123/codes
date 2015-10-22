using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	int n = read ();
	int k = read ();
	
	int count = 0;
	
	while (n--)
	{
		int t = read ();
		if (t % k == 0)
		  count ++;
	}
	
	printf ("%d\n", count);
	
	return 0;
}