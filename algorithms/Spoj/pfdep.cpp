using namespace std;

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

int n, m, in[101];
vector <int> adj[101], order;
priority_queue < int, vector <int>, greater <int> > seq;

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
	memset (in, 0, sizeof (in));
	n = read ();
	m = read ();
	for (int i = 0; i < m; i++)
	{
		int t0 = read (), k = read ();
		for (int j = 0; j < k; j++)
		{
			int t = read ();
			adj[t].push_back(t0);
		}
		in[t0] += k;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!in[i])
		  seq.push (i);
	}
	
	while (!seq.empty ())
	{
		int u = seq.top ();
		seq.pop ();
		order.push_back (u);
		for (unsigned int j = 0; j < adj[u].size (); j++)
		{
			int v = adj[u][j];
			in[v]--;
			if (!in[v])
			  seq.push (v);
		}
	}
	for (int i = 0; i < n-1; i++)
	  printf ("%d ", order[i]);
	printf ("%d\n", order[n-1]);

	return 0;
}