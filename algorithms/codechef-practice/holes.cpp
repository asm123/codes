using namespace std;

#include <iostream>
#include <stdio.h>

inline short int read ()
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
	short int t = read ();
	while (t--)
	{
		char text[100];
		scanf ("%s", text);
		short int count = 0;
		char c = text[0];
		short int i = 0;
		while (c != '\0')
		{
			switch (c)
			{
			  case 'A': case 'D': case 'O': case 'P': case 'Q': case 'R': count++; break;
			  case 'B': count += 2; break;
			}
			c = text[++i];
		}
		
		printf ("%d\n", count);
	}
	
	return 0;
}