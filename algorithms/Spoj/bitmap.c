#include <stdio.h>
#include <stdlib.h>

int n, m;
char bitmap[192][192];
int dist[192][192];

void DFS (int, int, int, int);

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
		int i, j, k, qx[40000], qy[40000];
		n = read ();
		m = read ();
		for (i = 0; i < n; i++)
		  for (j = 0; j < m; j++)
		    dist[i][j] = 100000;
		k = 0;
		for (i = 0; i < n; i++)
		{
			scanf ("%s", bitmap[i]);
			for (j = 0; j < m; j++)
			{
				if (bitmap[i][j] == '1')
				{
					qx[k] = i;
					qy[k] = j;
					dist[i][j] = 0;
					k++;
				}
			}
		}
		
		for (i = 0; i < k; i++)
		{
			int x = qx[i];
			int y = qy[i];
			DFS (x, y, x - 1, y);
			DFS (x, y, x + 1, y);
			DFS (x, y, x, y - 1);
			DFS (x, y, x, y + 1);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			  printf ("%d ", dist[i][j]);
			printf ("\n");
		}
	}
	return 0;
}

void DFS (int i1, int j1, int i2, int j2)
{
	if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m)
	{
		if (bitmap[i2][j2] == '1')
		  return;
		int i = i1 - i2, j = j1 - j2;
		if (i < 0) i *= -1;
		if (j < 0) j *= -1;
		int d = i + j;
		if (dist[i2][j2] <= d)
		  return;
		dist[i2][j2] = d;
		DFS (i1, j1, i2 - 1, j2);
		DFS (i1, j1, i2 + 1, j2);
		DFS (i1, j1, i2, j2 - 1);
		DFS (i1, j1, i2, j2 + 1);
	}
}