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
	int a = read (), n = read (), k = read ();
	if (n == 0)
	  a = 0;
	while (k--)
	{
		if (a != 0)
		{
			printf ("%d ", a % (n + 1));
			a /= (n + 1);
		}
		else
		{
			if (k == 0)
			  printf("0\n");
			else
			  printf("0 ");
		}
	}
	
	return 0;
}