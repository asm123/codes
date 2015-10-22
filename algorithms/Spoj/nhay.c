#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

int * kmp_table (char * pattern, int n)
{
	int * T = (int *) malloc (sizeof (int) * (n + 1));
	int i;
	T[0] = -1;
	for (i = 0; pattern[i]; i++)
	{
		T[i + 1] = T[i] + 1;
		while (T[i + 1] > 0 && pattern[i] != pattern[T[i + 1] - 1])
		  T[i + 1] = T[T[i + 1] - 1] + 1;
	}
	return T;
}

void kmp (char * pattern, int n)
{
	int * T = kmp_table (pattern, n);
	int i = 0, j = 0;
	char ch;
	while (1)
	{
		ch = getchar ();
		if (ch == '\n')
		  break;
		while (1)
		{
			if (ch == pattern[i])
			{
				i++;
				if (i == n)
				{
					printf ("%d\n", j - n + 1);
					count++;
					i = T[i];
				}
				break;
			}
			else if (i == 0)
			  break;
			else
			  i = T[i];
		}
		j++;
	}
	free (T);
}

int main (void)
{
	int n;
	while (scanf ("%d", &n) == 1)
	{
		getchar ();
		char pattern[n + 1];
		gets (pattern);
		kmp (pattern, strlen (pattern));
		if (count == 0)
		  printf ("\n");
		count = 0;
	}
	return 0;
}