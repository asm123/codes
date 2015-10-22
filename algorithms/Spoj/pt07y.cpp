using namespace std;

#include <cstdio>
#include <vector>
#include <queue>
#define max 10001

int n, m;
vector <int> adj[max];
bool visited [max];
int parent[max];

bool BFS (int);

int main (void)
{
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
		parent[i] = 0;
	}
	
	int u;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		adj[a].push_back (b);
		adj[b].push_back (a);
		u = a;
	}
	if (m != n-1)
	  printf ("NO\n");
	else
	{
		if (BFS(u))
		  printf ("YES\n");
		else
		  printf ("NO\n");
	}
	return 0;
}

bool BFS (int s)
{
	queue <int> q;
	visited[s] = true;
	
	q.push (s);
	
	while (!q.empty ())
	{
		int u = q.front ();
		q.pop ();
		for (unsigned int i = 0; i < adj[u].size (); i++)
		{
			int v = adj[u][i];
			if (parent[u] != v && visited[v])
			  return false;
			if (!visited[v])
			{
				parent[v] = u;
				visited[v] = true;
				q.push (v);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	  if (!visited[i])
	    return false;
	  
	return true;
}