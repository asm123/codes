#include <cstdio>
#include <cstring>

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


int min (int x, int y) { return y ^ ((x ^ y) & -(x < y)); }

int dp[2002][2002];

int editDistance (char s1[], char s2[])
{
	int m = strlen (s1);
	int n = strlen (s2);
	
	for (int i = 0; i < m; i++)
		dp[i][0] = i;
	for (int i = 0; i < n; i++)
		dp[0][i] = i;
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int left = dp[i][j-1] + 1;
			int right = dp[i-1][j] + 1;
			int diag = dp[i-1][j-1] + (s1[i-1] != s2[j-1]);
			dp[i][j] = min (min (left, right), diag);
		}
	}
	return dp[m][n];
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		char s1[2001], s2[2001];
		scanf ("%s%s", s1, s2);
		printf ("%d\n", editDistance (s1, s2));
	}
	return 0;
}
