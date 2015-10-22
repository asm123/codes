#include <stdio.h>

int getRoot (char * s)
{
	int count[36] = {0};
	int i = 0, min = 100000000, n = 0;
	while (s[i])
	{
		int c;
		if (s[i] >= 'a' && s[i] <= 'z')
			c = s[i] - 'a';
		else
			c = s[i] - '0' + 26;
		count[c]++;
		i++;
		n++;
	}
	
	for (i = 0; i < 36; i++)
	{
		if (count[i] > 0 && count[i] < min)
			min = count[i];
	}
	if (n % min)
		return 1;
	int len = n / min;
	char temp[len + 1];
	for (i = 0; i < len; i++)
		temp[i] = s[i];
	temp[len] = '\0';
	i = len;
	while (s[i])
	{
		int j;
		for (j = 0; j < len; j++)
		{
			if (temp[j] != s[i])
				return 1;
			i++;
		}
	}
	
	return min;
}

int main (void)
{
	while (1)
	{
		char s[1000000];
		scanf ("%s", s);
		if (s[0] == '*')
			break;
		printf ("%d\n", getRoot (s));
	}
		
	return 0;
}
