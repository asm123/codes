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

int max (int a, int b) { return (a > b) ? a : b; }
int min (int a, int b) { return (a < b) ? a : b; }

void printMaxMin (char * s)
{
	int i, l, n , o;
	int num[1001], op[1001];
	
	i = 0; n = 0; o = 0;
	while (s[i])
	{
		if (i % 2)
			op[o++] = s[i];
		else
			num[n++] = s[i] - '0';
		i++;
	}
	
	int val[n][n];
	
	for (i = 0; i < n; i++)
		val[i][i] = num[i];
	
	for (l = 2; l <= n; l++)
	{
		for (i = 0; i < n-l+1; i++)
		{
			int j, k;
			j = i + l - 1;
			val[i][j] = 0;
			
			for (k = i; k < j; k++)
			{
				if (op[k] == '+')
					val[i][j] = max (val[i][j], val[i][k] + val[k + 1][j]);
				else
					val[i][j] = max (val[i][j], val[i][k] * val[k + 1][j]);
			}
		}
	}
	printf ("%d ", val[0][n - 1]);
	
	for (l = 2; l <= n; l++)
	{
		for (i = 0; i < n-l+1; i++)
		{
			int j, k;
			j = i + l - 1;
			val[i][j] = 100000000;
			
			for (k = i; k < j; k++)
			{
				if (op[k] == '+')
					val[i][j] = min (val[i][j], val[i][k] + val[k + 1][j]);
				else
					val[i][j] = min (val[i][j], val[i][k] * val[k + 1][j]);
			}
		}
	}
	printf ("%d\n", val[0][n - 1]);
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		char s[110];
		scanf ("%s", s);
		printMaxMin (s);
	}
	
	return 0;
}
