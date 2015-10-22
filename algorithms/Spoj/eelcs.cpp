#include <cstdio>
#include <cstring>

int max (int a, int b) { return ((a > b) ? a : b); }

int LCS (char A[], char B[], int a, int b)
{
	int lcs[a + 1][b + 1];
	
	for (int i = 0; i <= a; i++)
		lcs[i][0] = 0;
	for (int i = 0; i <= b; i++)
		lcs[0][i] = 0;
	
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (A[i-1] == B[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max (lcs[i-1][j], lcs[i][j-1]);
		}
	}
	return lcs[a][b];
}

int main (void)
{
	char A[100], B[100];
	scanf ("%s%s", A, B);
	printf ("%d\n", LCS (A, B, strlen (A), strlen (B)));
	return 0;
}
