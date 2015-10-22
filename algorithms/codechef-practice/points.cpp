#include <stdio.h>
#include <cmath>

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
	char t = read ();
	while (t--)
	{
		int n = read ();
		int point[10001][2];
		for (int i = 0; i <= 10000; i++)
		{
			point[i][0] = 10001;
			point[i][1] = -1;
		}
		int maxx = -1;
		while (n--)
		{
			int x = read ();
			int y = read ();
			if (y < point[x][0]) // 0 stores min y
			  point[x][0] = y;
			if (y > point[x][1]) // 1 stores max y
			  point[x][1] = y;
			if (x > maxx)
			  maxx = x;
		}
		double dist = 0;
		int prevX = -1, prevY = -1;
		for (int i = 0; i <= maxx; i++)
		{
			if (point[i][1] == -1)
			  continue;
			if (prevX != -1)
			  dist += sqrt ((prevX - i) * (prevX - i) + (prevY - point[i][1]) * (prevY - point[i][1]));
			dist += point[i][1] - point[i][0];
			prevX = i;
			prevY = point[i][0];
		}
		printf ("%.2f\n", dist);
	}
	return 0;
}