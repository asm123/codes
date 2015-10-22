#include <cstdio>

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
	int sum, best, bestLeft, bestRight;
} tree [2 * MAX];

int max (int a, int b) { return ((a > b)? a : b); }

void init (int i, int start, int end)
{
	if (start == end)
	{
		tree[i].sum = tree[i].best = tree[i].bestLeft = tree[i].bestRight = a[start];
		return;
	}
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = start + (end - start) / 2;
	init (l, start, m);
	init (r, m + 1, end);
	
	tree[i].sum = tree[l].sum + tree[r].sum;
	tree[i].bestLeft = max (tree[l].bestLeft, tree[l].sum + tree[r].bestLeft);
	tree[i].bestRight = max (tree[r].bestRight, tree[r].sum + tree[l].bestRight);
	tree[i].best = max (max (tree[l].best, tree[r].best), tree[l].bestRight + tree[r].bestLeft);
}

struct node query (int i, int S, int E, int x, int y)
{
	if (x <= S && y >= E)
		return tree[i];
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = S + (E-S) / 2;
	if (y <= m)
		return query (l, S, m, x, y);
	else if (x > m)
		return query (r, m+1, E, x, y);
	else
	{
		struct node t1, t2, t3;
		
		t1 = query (l, S, m, x, y);
		t2 = query (r, m+1, E, x, y);
		
		t3.sum = t1.sum + t2.sum;
		t3.bestLeft = max (t1.bestLeft, t1.sum + t2.bestLeft);
		t3.bestRight = max (t2.bestRight, t2.sum + t1.bestRight);
		t3.best = max (max (t1.best, t2.best), t1.bestRight + t2.bestLeft);
		
		return t3;
	}	
}

int main (void)
{
	int N = read ();
	for (int i = 0; i < N; i++)
		scanf ("%d", &a[i]);
	init (1, 0, N-1);
	int M = read ();
	while (M--)
	{
		int x = read ();
		int y = read ();
		printf ("%d\n", query (1, 0, N-1, x-1, y-1).best);
	}
	
	return 0;
}
