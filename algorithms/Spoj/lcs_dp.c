#include <stdio.h>
#include <string.h>

int max (int a, int b) { return (a > b) ? a : b; }

int lengthOfLCS (char s1[], char s2[])
{
	int m = strlen (s1);
	int n = strlen (s2);
	int LCS[m + 1][n + 1];
	int i, j;
	for (i = 0; i <= m; i++)
		LCS[i][0] = 0;
	for (i = 0; i <= m; i++)
		LCS[0][i] = 0;
	int maxLen = 0;
	
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				maxLen = max (maxLen, LCS[i][j]);
			}
			else
				LCS[i][j] = 0;
		}
	}
	return maxLen;
}

int main (void)
{
	char s1[250010], s2[250010];	
	scanf ("%s %s", s1, s2);
	printf ("%d\n", lengthOfLCS (s1, s2));
	
	return 0;
}
