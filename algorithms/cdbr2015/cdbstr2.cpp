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

int min (int a, int b) { return (a < b) ? a : b; }

int editDistance (char *A, char *B)
{
	int a = strlen(A);
	int b = strlen(B);
	int dp[a+1][b+1];
	
	for (int i = 0; i <= a; i++)
		dp[i][0] = i;
	for (int j = 0; j <= b; j++)
		dp[0][j] = j;
		
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			int addDist = dp[i][j-1] + 1;
			int deleteDist = dp[i-1][j] + 1;
			int replaceDist = dp[i-1][j-1] + (A[i-1] != B[j-1]);
			dp[i][j] = min (min (addDist, deleteDist), replaceDist);
		}
	}
	return dp[a][b];
}

int main (void)
{
	int T = read();
	while (T--)
	{
		char A[2002], B[2002];
		scanf("%s%s", A, B);
		printf ("%d\n", editDistance (A, B));
	}
	return 0;
}
