#include <stdio.h>

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

int getCandidate (int a[], int n)
{
	int index = 0, count = 1, i;
	
	for (i = 1; i < n; i++)
	{
		if (a[i] == a[index])
			count++;
		else
			count--;
		if (count == 0)
		{
			index = i;
			count = 1;
		}
	}
	return a[index];
}

int checkCandidate (int a[], int n, int cand)
{
	int count = 0, i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == cand)
			count++;
	}
	if (count > n/2)
		return 1;
	return 0;
}

void printMajorityElement (int a[], int n)
{
	int cand = getCandidate (a, n);
	if (checkCandidate (a, n, cand))
		printf ("%d\n", cand);
}

int main (void)
{
	int n = read ();
	int a[n], i;
	for (i = 0; i < n; i++)
		a[i] = read ();
	printMajorityElement (a, n);
	return 0;
}
