#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

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

char *strrev (char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int max (int a, int b)
{
	return (a > b ? a : b);
}

int lcs (char* s1, char* s2, int m, int n)
{
	static short lcs[6101][6101];
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (s1[i-1] == s2[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max (lcs[i][j-1], lcs[i-1][j]);
		}
	}
	return lcs[m][n];
}

int findMinInsertions (char* str, int len)
{
	char rev[len+1];
	strcpy (rev, str);
	strrev (rev);
	return (len - lcs (str, rev, len, len));
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		char str[6101];
		scanf ("%s", str);
		// lcs approach
		printf ("%d\n", findMinInsertions (str, strlen (str)));
	}
	return 0;
}
