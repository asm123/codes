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
		char s1[1000000], s2[1000000];
		int count[26] = {0};
		
		scanf("%s %s", s1, s2);
		
		int i = 0;
		while (s1[i])
		{
			count[s1[i] - 'a']++;
			i++;	
		}
		
		i = 0;
		bool flag = false;
		while (s2[i])
		{
			count[s2[i] - 'a']--;
			if (count[s2[i] - 'a'] == 0)
			{
				
				flag = true;
				printf ("Yes\n");
				break;
			}
			i++;
		}
		if (!flag)
			printf ("No\n");
	}
	return 0;
}

