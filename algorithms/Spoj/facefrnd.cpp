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
	int friends[100000] = {0};
	int N = read();
	for (int i=0; i<N; i++)
	{
		int b_friend = read();
		friends[b_friend] = 1;
		int n_friend = read();
		for (int j=0; j<n_friend; j++)
		{
			int f_friend = read();
			if (!friends[f_friend])
				friends[f_friend] = -1;
		}	
	}
	int cnt = 0;
	for (int i = 0; i < 100000; i++)
		if (friends[i] == -1)
			cnt++;
	printf ("%d\n", cnt);
	return 0;
}
