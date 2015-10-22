#include <cstdio>
#include <cstring>

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
		char s[1000];
		int count = 0;
		scanf("%s", s);
		int len = strlen (s);
		for (int i = 0; i < )
	}
	return 0;
}
