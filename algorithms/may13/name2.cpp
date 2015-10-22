using namespace std;

#include <iostream>
#include <string>
#include <cstdio>


inline short int read ()
{
	char c;
	short int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

bool isSubsequence (char * M, char * W)
{
	int i = 0;
	
	for (int j = 0; W[j]; j++)
	{
		if (M[i] == W[j])
			i++;
		if (M[i])
				continue;
		return true;
	}
	return false;
}

int main (void)
{
	short int T = read ();
	while (T--)
	{
		char M[25100], W[25100];
		scanf ("%s%s", M, W);
		if (isSubsequence (M, W) || isSubsequence (W, M))		
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}
