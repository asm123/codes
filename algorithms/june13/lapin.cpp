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
	int T = read ();
	while (T--)
	{
		int count[26] = {0};
		char s[10000];
		scanf ("%s", s);
		int len = strlen (s);
		int e, b;
		e = len / 2 -1;
		b = len / 2;
		if (len % 2)
			b++;
		for (int i = 0; i <= e; i++)
			count[s[i] - 'a']++;
		for (int i = b; s[i]; i++)
			count[s[i] - 'a']--;
		bool is = true;
		for (int i = 0; i < 26; i++)
		{
			if (count[i] != 0)
			{
				is = false;
				break;
			}
		}	
		if (is)
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}
