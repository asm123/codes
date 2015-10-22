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

long long tree[MAX][2]; // 0: sum, 1: add

void update (int i, int S, int E, int p, int q, int v)
{
	if (p == S && q == E)
	{
		tree[i][1] += v;
		tree[i][0] += (long long)v * (q - p + 1);
		return;
	}
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = S + (E-S) / 2;
	if (q <= m)
		update (l, S, m, p, q, v);
	else if (p > m)
		update (r, m+1, E, p, q, v);
	else
	{
		update (l, S, m, p, m, v);
		update (r, m+1, E, m+1, q, v);
	}
	tree[i][0] = tree[l][0] + tree[r][0] + tree[i][1] * (E - S + 1);
}

long long query (int i, int S, int E, int p, int q, long long v)
{
	if (p == S && q == E)
		return tree[i][0] + v * (q - p + 1);
	int l, r, m;
	l = 2 * i;
	r = l + 1;
	m = S + (E - S) / 2;
	if (q <= m)
		return query (l, S, m, p, q, v + tree[i][1]);
	else if (p > m)
		return query (r, m+1, E, p, q, v + tree[i][1]);
	else
		return (query (l, S, m, p, m, v + tree[i][1]) + query (r, m+1, E, m+1, q, v + tree[i][1]));
}

int main (void)
{
	int T = read ();
	while (T--)
	{
		int N = read ();
		int C = read ();
		memset (tree, 0, sizeof (tree));
		while (C--)
		{
			int op = read (), p = read (), q = read ();
			if (op)
				printf ("%lld\n", query (1, 0, N-1, p-1, q-1, 0));
			else
			{
				int v = read ();
				update (1, 0, N-1, p-1, q-1, v);
			}
		}
	}
	return 0;
}
