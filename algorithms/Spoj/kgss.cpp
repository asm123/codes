using namespace std;

#include <cstdio>
#include <cstdlib>

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

const int MAX = 1000000;

struct node { int max1, max2; } tree[MAX];

int * a;

int compare (const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void init (int Node, int S, int E)
{
	if (S == E)
	{
		tree[Node].max1 = a[S];
		tree[Node].max2 = 0;
		return;
	}
	int l, r, m;
	l = 2 * Node;
	r = l + 1;
	m = S + (E - S) / 2;
	
	init (l, S, m);
	init (r, m+1, E);
	
	int t[4];
	t[0] = tree[l].max1;	t[1] = tree[l].max2;	t[2] = tree[r].max1;	t[3] = tree[r].max2;
	qsort (t, 4, sizeof (int), compare);
	tree[Node].max1 = t[3];
	tree[Node].max2 = t[2];
}

void update (int Node, int S, int E, int idx, int val)
{
	if (S == E)
	{
		a[S] = val;
		tree[Node].max1 = val;
		tree[Node].max2 = 0;
		return;
	}
	int l, r, m;
	l = 2 * Node;
	r = l + 1;
	m = S + (E-S) / 2;
	if (idx <= m)
		update (l, S, m, idx, val);
	else
		update (r, m+1, E, idx, val);
	int t[4];
	t[0] = tree[l].max1;	t[1] = tree[l].max2;	t[2] = tree[r].max1;	t[3] = tree[r].max2;
	qsort (t, 4, sizeof (int), compare);
	tree[Node].max1 = t[3];
	tree[Node].max2 = t[2];
}

struct node query (int Node, int S, int E, int x, int y)
{
	struct node q;
	if ((S == x && E == y) || S == E)
	{
		q.max1 = tree[Node].max1;
		q.max2 = tree[Node].max2;
	}
	else
	{
		int l, r, m;
		l = 2 * Node;
		r = l + 1;
		m = S + (E-S) / 2;
		if (y <= m)
			q = query (l, S, m, x, y);
		else if (x > m)
			q = query (r, m+1, E, x, y);
		else
		{
			struct node q1, q2;
			
			q1 = query (l, S, m, x, m);
			q2 = query (r, m+1, E, m+1, y);
			
			int t[4];
			t[0] = q1.max1;	t[1] = q1.max2; t[2] = q2.max1; t[3] = q2.max2;
			qsort (t, 4, sizeof (int), compare);
			
			q.max1 = t[3]; q.max2 = t[2];
		}
	}
	return q;
}

int main (void)
{
	int n = read (), i, q;
	a = (int *) malloc (n * sizeof (int));
	for (i = 0; i < n; i++)
	  a[i] = read ();
	init (1, 0, n-1);
	q = read ();
	while (q--)
	{
		char op;
		scanf ("%c", &op);
		int x = read (), y = read ();
		if (op == 'U')
			update (1, 0, n-1, x-1, y);
		else
		{
			struct node t = query (1, 0, n-1, x-1, y-1);
			printf ("%d\n", t.max1 + t.max2);
		}	
	}
	free(a);
	return 0;
}
