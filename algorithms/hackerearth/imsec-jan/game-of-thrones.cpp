#include <iostream>
#include <cstdio>
#include <set>

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
	int T = read();
	while (T--)
	{
		set <int> codes;
		int n = read(), count = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (codes.count(x))
				count++;
			else
				codes.insert(x);
		}
		printf ("%d\n", count);
	}
	
	
	return 0;
}
