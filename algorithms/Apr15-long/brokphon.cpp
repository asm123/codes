#include <iostream>
#include <cstdio>

int main (void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf ("%d", &N);
		int prev = 0;
		int cnt = 0;
		bool prevCounted = false;
		for (int i = 0; i < N; i++)
		{
			int x;
			scanf ("%d", &x);
			if (i != 0)
			{
				if (x != prev)
				{
					cnt++;
					if (!prevCounted)
						cnt++;
					prevCounted = true;
				}
				else
					prevCounted = false;
			}
			prev = x;
		}
		printf ("%d\n", cnt);
	}
	
	return 0;
}
