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
		int N = read(), K = read();
		char s[N+1];
		int dot[N+1];
		scanf("%s", s);
		int i = 0, k = 1;
		dot[0] = -1;
		while (s[i])
		{
			if (s[i] == '.')
				dot[k++] = i;
			i++;
		}
		dot[k++] = i;
		/*for (i = 0; i < k; i++)
		{
			printf ("dot: %d\n", dot[i]);
		}*/
		for (i = 1; i < k; i++)
		{
			if (dot[i] - dot[i-1] > K)
			{
				printf ("NO\n");
				break;
			}
		}
		if (i == k)
			printf ("YES\n");
	}
	return 0;
}
