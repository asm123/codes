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

unsigned long long getSum(unsigned long long int a[], unsigned long long int b[], int l, int r)
{
	unsigned long long sum = 0;
	if ((r-l) % 2)
	{
		if (l == 0 || l == 1)
		{
			sum += a[r-1];
			if (l == 0)
				sum += b[r];
			else
				sum += b[r] - b[0];
		}
		else
			sum += (a[r-1] - a[l-2]) + (b[r] - b[l-1]);
	}
	else
	{
		if (l == 0 || l == 1)
		{
			sum += a[r];
			if (l == 0)
				sum += b[r-1];
			else
				sum += b[r-1] - b[0];
		}
		else
			sum += (a[r] - a[l-2]) + (b[r-1] - b[l-1]);
	}
	return sum;
}

int main (void)
{
	int N = read(), Q = read();
	unsigned long long int a[N], b[N];
	for (int i = 0; i < N; i++)
	{
		scanf ("%llu", &a[i]);
		if (i > 1)
			a[i] += a[i-2];
	}
	for (int i = 0; i < N; i++)
	{
		scanf ("%llu", &b[i]);
		if (i > 1)
			b[i] += b[i-2];
	}
	
	for (int i = 0; i < Q; i++)
	{
		int q, l, r;
		scanf ("%d%d%d", &q, &l, &r);
		l -= 1;
		r -= 1;
		if (q == 1)
			printf ("%llu\n", getSum(a,b,l,r));
		else
			printf ("%llu\n", getSum(b,a,l,r));
	}
	
	return 0;
}

