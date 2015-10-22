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

void multiply (long long int fib[2][2], long long int x[2][2])
{
	long long int a = ((fib[0][0] * x[0][0]) % 1000000007 + (fib[0][1] * x[1][0]) % 1000000007) % 1000000007;
	long long int b = ((fib[0][0] * x[0][1]) % 1000000007 + (fib[0][1] * x[1][1]) % 1000000007) % 1000000007;
	long long int c = ((fib[1][0] * x[0][0]) % 1000000007 + (fib[1][1] * x[1][0]) % 1000000007) % 1000000007;
	long long int d = ((fib[1][0] * x[0][1]) % 1000000007 + (fib[1][1] * x[1][1]) % 1000000007) % 1000000007;
	
	fib[0][0] = a; fib[0][1] = b;
	fib[1][0] = c; fib[1][1] = d;
}

void power (long long int fib[2][2], int n)
{
	if (n == 0 || n == 1)
	  return;
	long long int x[2][2] = {{1,1}, {1,0}};
	power (fib, n/2);
	multiply (fib, fib);
	
	if (n % 2)
	  multiply (fib, x);
}

long long int fibo (int n)
{
	long long int fib[2][2] = {{1,1}, {1,0}};
	if (n == 0)
	  return 0;
	power (fib, n-1);
	return fib[0][0];
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		int n = read (), m = read ();
		printf ("%lld\n", (fibo (m+2) - fibo (n+1) + 1000000007) % 1000000007);
	}
	return 0;
}