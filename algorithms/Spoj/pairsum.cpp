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

int main (void)
{
	int n = read ();
	unsigned long long a[n], sum[n], mul[n];
	a[0] = read ();
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		a[i] = read ();
		sum[i] = sum[i-1] + a[i];
	}	
	mul[0] = sum[0] * a[0];
	for (int i = 1; i < n; i++)
		mul[i] = mul[i-1] + a[i] * sum[i];
	
	int M = read ();
	while (M--)
	{
		int u = read (), v = read ();
		unsigned long long psum;
		if (u == 0)
			psum = mul[v];
		else
			psum = mul[v] - mul[u-1] - sum[u-1] * (sum[v] - sum[u-1]);
		printf ("%llu\n", psum);
	}
}
