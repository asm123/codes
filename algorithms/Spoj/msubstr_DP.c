#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printNumberOfMirrorStrings (char * s)
{
	int n = strlen (s);
	int max_arr[3001] = {0};
	int max = 1, i, j, len;
	int ** P = (int **) malloc (n * sizeof (int *));
	for (i = 0; i < n; i++)
		P[i] = (int *) malloc (n * sizeof (int));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			P[i][j] = 0;
	
	max_arr[1] = n;
	
	// 1-length palindromes
	
	for (i = 0; i < n; i++)
		P[i][i] = 1;
		
	// 2-length palindromes
	
	for (i = 0; i < n-1; i++)	
	{
		if (s[i] == s[i + 1])
		{
			P[i][i+1] = 1;
			max = 2;
			max_arr[max]++;
		}
	}
	
	// >2-length palindromes
	
	for (len = 3; len <= n; len++)
	{
		for (i = 0; i < n-len+1; i++)
		{
			j = i + len - 1;
			if (s[i] == s[j] && P[i+1][j-1] == 1)
			{
				P[i][j] = 1;
				max = len;
				max_arr[max]++;
			}
		}
	}
	
	printf ("%d %d\n", max, max_arr[max]);
	
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		char s[3001];
		scanf ("%s", s);
		printNumberOfMirrorStrings (s);
	}
	return 0;
}
