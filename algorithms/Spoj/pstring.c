#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preprocess (char * Y, int * lps)
{
	int i, len;
	
	lps[0] = 0;
	len = 0;
	i = 1;
	
	while (Y[i])
	{
		if (Y[i] == Y[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
			else
				len = lps[len - 1];
		}
	}
}

int getCount (char * X, char * Y)
{
	int y = strlen (Y);
	int * lps = (int *) malloc (sizeof (int) * y);
	preprocess (Y, lps);
	
	int i = 0, j = 0, count = 0;
	
	while (X[i])
	{
		if (X[i] == Y[j])
		{
			i++;
			j++;
		}
		if (!Y[j])
		{
			count++;
			j--;
		}
		else if (X[i] != Y[j])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	free (lps);
	return count;
}

int main (void)
{
	char X[10010], Y[1010];
	while (scanf ("%s %s", X, Y))
	{
		printf ("%d\n", getCount (X, Y));
	}
	return 0;
}
