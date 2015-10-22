#include <stdio.h>
#include <stdlib.h>

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

char * preprocess (char * s, int n)
{
	char * T = (char *) malloc (sizeof (char) * (2*n + 4));
	int i = 0, j = 1;
	T[0] = '^';
	
	while (s[i])
	{
		T[j++] = '#';
		T[j++] = s[i];
		i++;
	}
	T[j++] = '#';
	T[j++] = '$';
	T[j] = '\0';
	
	return T;
}

int min (int x, int y) { return ((x < y) ? x : y); }

void printNumberOfMirrorStrings (char * s)
{
	int max = 0, i, C = 0, R = 0, n = 0;
	
	i = 0;
	while (s[i++])
		n++;
	char * T = preprocess (s, n);
	n = 0;
	i = 0;
	while (T[i++])
		n++;
	int * P = (int *) malloc (n * sizeof (int));
	
	int max_arr[3001] = {0};
	
	for (i = 0; i < n; i++)
		P[i] = 0;
	
	for (i = 1; i < n-1; i++)
	{
		int i_mirror = C - (i - C);
		
		P[i] = (R > i) ? min (R - i, P[i_mirror]) : 0;
		
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
		
		if (i + P[i] > R)
		{
			C = i;
			R = i + P[i];
		}
	}
	
	for (i = 1; i < n-1; i++)
	{
		if (P[i] > max)
		{
			max = P[i];
		}
		max_arr[P[i]]++;
	}
	
	printf ("%d %d\n", max, max_arr[max]);
	
	free (P);
	free (T);
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
