using namespace std;

#include <iostream>
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

int main (void)
{
	int t = read ();
	while (t--)
	{
		int mat[100][100];
		for (int i = 0; i < 100; i++)
		  for (int j = 0; j < 100; j++)
		    mat[i][j] = 0;
		int n = read ();
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				mat[i][j] = read ();
				if (i > 0)
				{
					if (j == 0)
					  mat[i][j] += mat[i-1][j];
					else
					  mat[i][j] += mat[i-1][j] > mat[i-1][j-1] ? mat[i-1][j] : mat[i-1][j-1];
				}
			}
		}
		for (int i = 0; i < n; i++)
		  sum = mat[n-1][i] > sum ? mat[n-1][i] : sum;
		printf ("%d\n", sum);
	}
	return 0;
}