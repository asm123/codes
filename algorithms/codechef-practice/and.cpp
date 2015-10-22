#include <cstdio>
#include <iostream>

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
	int N = read ();
	long long A[N];
	for (int i = 0; i < N; i++)
		scanf ("%lld", &A[i]);
	long long and_sum = 0;
	if (N > 1000)
	{
		int no_of_1 = 0;
		int no_of_0 = 0;
		for (int i = 0; i < N; i++)
			if (A[i] == 1)
				no_of_1++;
		and_sum = (long long)no_of_1 * ((long long)no_of_1 - 1) / 2;
	}
	else
	{
		for (int i = 0; i < N; i++)
			for (int j = i+1; j < N; j++)
				and_sum += A[i] & A[j];
	}
	printf ("%lld\n", and_sum);
	return 0;
}
