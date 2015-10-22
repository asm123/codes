#include <iostream>
#include <cstdio>
#include <map>
#define MAX 1000000

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
	map <long long, int> sqrs;
	for (int i = 0; i <= MAX; i++)
		sqrs[i*i] = 1;
	for (int i = 0; i <= MAX; i++)
	{
		if (sqrs[i] != 1)
			sqrs[i] = 0;
	}

	int t = read ();
	while (t--)
	{
		long long n;
		scanf ("%lld", &n);
		map <long long, int> :: iterator it;
		for (it = sqrs.begin (); it != sqrs.end (); it++)
		{
			long long x = it -> first;
			if (x > n)
			{
				printf ("No\n");
				break;
			}
			if (sqrs[n - sqrs[x]] == 1)
			{
				printf ("Yes\n");
				break;
			}
		}
	}
	return 0;
}
