#include <iostream>
#include <cstdio>

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
	int N = read ();
	int b[N];
	for (int i = 0; i < N; i++)
		b[i] = read ();
	int Q = read ();
	for (int i = 0; i < Q; i++)
	{
		int L = read ();
		int R = read ();
	}
}
