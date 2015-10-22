using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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

struct node
{
	int d[3];
	int count;
} tree [MAX];

void init (int i, int start, int end)
{
	if (start == end)
	{
		tree[i].d[0] = 1;
		return;
	}
	int left = 2*i;
	int right = left + 1;
	int mid = start + (end - start) / 2;
	init (left, start, mid);
	init (right, mid + 1, end);
	tree[i].d[0] = tree[left].d[0] + tree[right].d[0];
}

int query (int i, int S, int E, int start, int end, int cnt)
{
	if (start == S && end == E)
	{
		if (cnt % 3 == 0)
			return tree[i].d[0];
		else if (cnt % 3 == 1)
			return tree[i].d[2];
		else if (cnt % 3 == 2)
			return tree[i].d[1];
	}
	int left = 2 * i;
	int right = left + 1;
	int mid = S + (E - S) / 2;
	cnt += tree[i].count;
	if (end <= mid)
		return query (left, S, mid, start, end, cnt);
	else if (start > mid)
		return query (right, mid + 1, E, start, end, cnt);
	else
		return query (left, S, mid, start, mid, cnt) + query (right, mid + 1, E, mid + 1, end, cnt);
}

void update (int i, int S, int E, int start, int end)
{
	if (start == S && end == E)
	{
		tree[i].count++;
		swap (tree[i].d[0], tree[i].d[1]);
		swap (tree[i].d[0], tree[i].d[2]);
		return;
	}
	int l, r, mid;
	l = i * 2;
	r = l + 1;
	mid = S + (E - S) / 2;
	if (end <= mid)
		update (l, S, mid, start, end);
	else if (start > mid)
		update (r, mid+1, E, start, end);
	else
	{
		update (l, S, mid, start, mid);
		update (r, mid+1, E, mid+1, end);
	}
	tree[i].d[0] = tree[l].d[0] + tree[r].d[0];
	tree[i].d[1] = tree[l].d[1] + tree[r].d[1];
	tree[i].d[2] = tree[l].d[2] + tree[r].d[2];
	
	switch (tree[i].count % 3)
	{
		case 1: swap (tree[i].d[0], tree[i].d[1]);
				swap (tree[i].d[0], tree[i].d[2]);
				break;
		case 2: swap (tree[i].d[0], tree[i].d[1]);
				swap (tree[i].d[1], tree[i].d[2]);
				break;
	}
}

int main (void)
{
	int n = read ();
	int q = read ();
	init (1, 0, n-1);
	while (q--)
	{
		int op = read ();
		int start = read ();
		int end = read ();
		
		if (op == 0)
			update (1, 0, n-1, start, end);
		else
			printf ("%d\n", query (1, 0, n-1, start, end, 0));
	}
	
	return 0;
}
