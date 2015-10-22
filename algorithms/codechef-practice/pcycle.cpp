using namespace std;

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
	int n = read ();
	int perm[n + 1];
	bool visited[n + 1];
	for (int i = 1; i <= n; i++)
	{
		perm[i] = read ();
		visited[i] = false;
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			while(1)
			{
				if (visited[i])
				  break;
				visited[i] = true;
				i = perm[i];
			}
			count++;
// 			printf ("\n");
		}
	}
	printf ("%d\n", count);
	for (int i = 1; i <= n; i++)
	  visited[i] = false;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			while(1)
			{
				printf ("%d ", i);
				if (visited[i])
				  break;
				visited[i] = true;
				i = perm[i];
			}
			printf ("\n");
		}
	}
	return 0;
}