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

int areAnagrams (char s1[], char s2[])
{
	int count[26] = {0};
	int i = 0;
	while (s1[i])
	{
		count[s1[i] - 'a']++;
		i++;
	}
	
	i = 0;
	while (s2[i])
	{
		count[s2[i] - 'a']--;
		i++;
	}
		
	for (i = 0; i < 26; i++)
	{
		if (count[i] != 0)
			return 0;
	}
	return 1;
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		char s1[22], s2[22];
		scanf ("%s %s", s1, s2);
		if (areAnagrams (s1, s2))
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	
	return 0;
}
