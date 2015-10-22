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

char s[MAX];

struct node
{
	int sum, minsum;
} tree[MAX];

int min (int a, int b) { return ((a < b) ? a : b); }

void init (int i, int S, int E)
{
	if (S == E)
	{
		if (s[S] == '(')
			tree[i].sum = tree[i].minsum = 1;
		else
			tree[i].sum = tree[i].minsum = -1;	
		return;
	}
	
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = S + (E - S) / 2;
	
	init (l, S, m);
	init (r, m+1, E);
	
	tree[i].sum = tree[l].sum + tree[r].sum;
	tree[i].minsum = min (tree[l].minsum, tree[l].sum + tree[r].minsum);
}

void update (int i, int S, int E, int k)
{
	if (S == E)
	{
		tree[i].sum = tree[i].minsum = -tree[i].sum;
		return;
	}
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = S + (E - S) / 2;
	if (k <= m)
		update (l, S, m, k);
	else
		update (r, m+1, E, k);
	tree[i].sum = tree[l].sum + tree[r].sum;
	tree[i].minsum = min (tree[l].minsum, tree[l].sum + tree[r].minsum);
}

int main (void)
{
	for (int T = 1; T <= 10; T++)
	{
		memset (tree, 0, sizeof (tree));
		int n = read ();
		scanf ("%s", s);
		init (1, 0, n-1);
		int m = read ();
		printf ("Test %d:\n", T);
		while (m--)
		{
			int k = read ();
			if (k)
				update (1, 0, n-1, k-1);
			else
			{
				if (!tree[1].sum && !tree[1].minsum)
					printf ("YES\n");
				else
					printf ("NO\n");
			}
		}
	}
	return 0;
}
