#include <stdio.h>

char desc[201][201];
int row, col;

void isHash (int, int);

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
		int count = 0, i, j;
		row = read ();
		col = read ();
		for (i = 0; i < row; i++)
		  scanf ("%s", desc[i]);
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (desc[i][j] == '#')
				{
					isHash (i, j);
					count++;
				}
			}
		}
		printf ("%d\n", count);
	}
	
	return 0;
}

void isHash (int i, int j)
{
	if (desc[i][j] == '#')
	{
		desc[i][j] = 'x';
		if (i > 0)
		{
			isHash (i - 1, j);
			if (j > 0)
			  isHash (i - 1, j - 1);
			if (j < col - 1)
			  isHash (i - 1, j + 1);
		}
		  
		if (j > 0)
		{
			isHash (i, j - 1);
			if (i < row - 1)
			  isHash (i + 1, j - 1);
		}
		if (j < col - 1)
		  isHash (i, j + 1);
		if (i < row - 1)
		  isHash (i + 1, j);
		if (i < row - 1 && j < col - 1)
		  isHash (i + 1, j + 1);
	}
}