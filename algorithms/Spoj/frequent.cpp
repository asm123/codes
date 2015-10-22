#include <cstdio>
#include <cstring>

const int MAX = (1 << 18);

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

int a[MAX];

struct node
{
	int mf, lf, rf;
} tree[MAX];

int max (int a, int b) { return ((a > b) ? a : b); }

void init (int i, int S, int E)
{
	if (S == E)
	{
		tree[i].mf = tree[i].lf = tree[i].rf = 1;
		return;
	}
	
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = S + (E - S) / 2;
	
	init (l, S, m);
	init (r, m+1, E);
}

int query (int index, int S, int E, int i, int j)
{
	
}

int main (void)
{
	int T;
	while ((T = read ()))
	{
		memset (tree, 0, sizeof (tree));
		int n = read (), q = read ();
		for (int i = 0; i < n; i++)
			scanf ("%d", &a[i]);
		init (1, 0, n-1);
		while (q--)
		{
			int i = read (), j = read ();
			if (i == j)
				printf ("1\n");
			else
				printf ("%d\n", query (1, 0, n-1, i-1, j-1));
		}
	}
	return 0;
}
