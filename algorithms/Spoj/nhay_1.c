#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int count = 0;

void computeLPSArray (char * pat, int * lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	
	while (pat[i])
	{
		if (pat[i] == pat[len])
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

void KMPSearch (char * pat, char * txt, int p)
{
	int * lps = (int *) malloc (sizeof (int) * p);
	computeLPSArray (pat, lps);
	
	int i = 0, j = 0;
	
	while (txt[i])
	{
		if (txt[i] == pat[j])
		{
			i++;
			j++;
		}
		if (!pat[j])
		{
			printf ("%d\n", (i - j));
			count++;
			j = lps[j - 1];
		}
		else if (txt[i] != pat[j])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}

	free (lps);
}

int main (void)
{
	int n;
	while (scanf ("%d", &n) == 1)
	{
		char pat[n + 1];
		scanf ("%s", pat);
		char txt[MAX + 1];
		scanf ("%s", txt);
		KMPSearch (pat, txt, n);
		if (count == 0)
			printf ("\n");
		count = 0;
	}
	return 0;
}

