#include <stdio.h>
#include <string.h>

int min (int a, int b)
{
	if (a < b)
	  return a;
	return b;
}

int main (void)
{
	char s1[1001], s2[1001];
	int a1[26], a2[26];
	while (scanf ("%s%s", s1, s2) != EOF)
	{
		memset (a1, 0, sizeof (a1));
		memset (a2, 0, sizeof (a2));
		int i = 0;
		while (s1[i])
		{
			a1[s1[i] - 'a']++;
			i++;
		}
		i = 0;
		while (s2[i])
		{
			a2[s2[i] - 'a']++;
			i++;
		}
		for (i = 0; i < 26; i++)
		{
			int l = min (a1[i], a2[i]);
			while (l--)
			  printf ("%c", i + 97);
		}
		printf ("\n");
	}
	return 0;
}