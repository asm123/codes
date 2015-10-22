#include <iostream>
#include <cstdio>
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

int main (void)
{
	int T = read ();
	while (T--)
	{
		char A[10002], B[10002];
		int count[62] = {0};
		scanf ("%s", A);
		int i = 0, lcpl = 0;
		while (A[i])
		{
			if (A[i] >= '0' && A[i] <= '9')
				count[A[i] - '0']++;
			else if (A[i] >= 'a' && A[i] <= 'z')
				count[A[i] - 'a' + 10]++;
			else if (A[i] >= 'A' && A[i] <= 'Z')
				count[A[i] - 'A' + 36]++;
			i++;
		}
		scanf ("%s", B);
		i = 0;
		while (B[i])
		{
			int ind = 0;
			if (B[i] >= '0' && B[i] <= '9')
				ind = B[i] - '0';
			else if (B[i] >= 'a' && B[i] <= 'z')
				ind = B[i] - 'a' + 10;
			else if (B[i] >= 'A' && B[i] <= 'Z')
				ind = B[i] - 'A' + 36;
			if (count[ind] > 0)
			{
				lcpl++;
				count[ind]--;
			}
			i++;
		}
		printf ("%d\n", lcpl);
	}
	return 0;
}
