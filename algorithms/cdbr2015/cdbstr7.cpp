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
		char M[500000], W[500000];
		int count[26] = {0};
		scanf("%s%s", M, W);
		int i = 0;
		while(M[i])
		{
			count[M[i] - 'a']++;
			i++;
		}
		i = 0;
		while(W[i])
		{
			count[W[i] - 'a']--;
			i++;
		}
		for (i=0; i<26; i++)
		{
			if(count[i] != 0)
			{
				printf("NO\n");
				break;
			}
		}
		if(i == 26)
			printf("YES\n");
	}
}
