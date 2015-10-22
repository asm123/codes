#include <cstdio>

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

int a[1000000], tree[1000000];

void query (int node, int l, int r, int index, int value)
{
	if (l == r)
		tree[node] = value;
	else
	{
		int mid = (l + r) / 2;
		int left = 2 * node;
		int right = left + 1;
		if (index <= mid)
			query (left, l, mid, index, value);
		else
			query (right, mid + 1, r, index, value);
		if (tree[left] >= tree[right])
			tree[node] = tree[left];
		else
			tree[node] = tree[right];
	}
}

int main (void)
{
	int n = read ();
	for (int i = 0; i < n; i++)
		a[i] = read ();
	int k = read ();
	
	for (int i = 0; i < k; i++)
		query (1, 0, k-1, i, a[i]);
	printf ("%d", tree[1]);
	
	for (int i = k; i < n; i++)
	{
		query (1, 0, k-1, i % k, a[i]);
		printf (" %d", tree[1]);
	}
	printf ("\n");
	
	return 0;
}
