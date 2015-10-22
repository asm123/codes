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
	int T = read ();
	while (T--)
	{
		char s1[500000], s2[500000];
		int count[36] = {0};
		
		scanf("%s %s", s1, s2);
		
		int i = 0;
		while (s1[i])
		{
			if (s1[i] >= 'a' && s1[i] <= 'z')
				count[s1[i] - 'a']++;
			else if (s1[i] >= '0' && s1[i] <= '9')
				count[s1[i] - '0' + 26]++;
			i++;	
		}
		
		i = 0;
		while (s2[i])
		{
			if (s2[i] >= 'a' && s2[i] <= 'z')
				count[s2[i] - 'a']--;
			else if (s2[i] >= '0' && s2[i] <= '9')
				count[s2[i] - '0' + 26]--;
			i++;
		}
		bool flag = false;
		for (i = 0; i < 36; i++)
		{
			if (count[i] != 0)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			printf ("NO\n");
		else
			printf ("YES\n");
	}
	return 0;
}

