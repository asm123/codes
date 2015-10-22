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
	int T = read ();
	while (T--)
	{
		float p;
		scanf ("%f", &p);
		float max = 0;
		for (int i = 0; i <= 10000; i++) // winning
		{
			for (int j = 10000-i; j >= 0; j--) // losing
			{
				float e = p*(i*2*(1-p)-j) + (1-p)*(j*2*p-i) + i;
				if (e > max)
					max = e;
			}
		}
		printf ("%f\n", max);
	}
	return 0;
}
