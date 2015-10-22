#include <iostream>
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
	int T = read();
	while (T--)
	{
		char s[1000000];
		scanf ("%s", s);
		int cnt = 0;
		for (int i = 1; s[i]; i++)
		{
			if ((s[i] == '-' && s[i-1] == '+') || (s[i] == '+' && s[i-1] == '-'))
				continue;
			
		}
		printf ("%d\n", cnt);
	}
	return 0;
}
