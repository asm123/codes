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

unsigned long int catalanDP(int n)
{
    unsigned long int catalan[n+1];
	catalan[0] = catalan[1] = 1;
 
    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
 
    return catalan[n];
}

int main (void)
{
	int T = read();
	while (T--)
	{
		int N = read();
		printf ("%lu\n", catalanDP(N));
	}
	return 0;
}
