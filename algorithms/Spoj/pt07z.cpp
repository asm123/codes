using namespace std;

#include <stdio.h>
#include <vector>
#include <algorithm>

vector <int> adj[10001];
int depth[10001];
bool visited[10001];

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

void DFS (int u, int d)
{
	visited[u] = true;
	depth[u] = d;
	for (unsigned int i = 0; i < adj[u].size (); i++)
	{
		int v = adj[u][i];
		if (!visited[v])
		  DFS (v, d + 1);
	}
}

int main (void)
{
	for (int i = 0; i < 10001; i++)
	{
		adj[i].clear ();
		visited[i] = false;
		depth[i] = 0;
	}
  
	int n = read ();
	for (int i = 1; i < n; i++)
	{
		int a = read (), b = read ();
		adj[a].push_back (b);
		adj[b].push_back (a);
	}
	
	DFS (1, 0);
	
	for (int i = 1; i <= n; i++)
	  visited[i] = false;
	
	int leaf = 1;
	for (int i = 1; i <= n; i++)
	{
		if (depth[i] > depth[leaf])
		  leaf = i;
	}
	
	DFS (leaf, 0);
	sort (depth, depth + n + 1);
	printf ("%d\n", depth[n]);
	
	return 0;
}