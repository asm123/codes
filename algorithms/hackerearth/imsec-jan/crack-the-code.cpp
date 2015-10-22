#include <iostream>
#include <cstdio>

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

int fibo[1000000] = {0};
void generate_fibonacci_numbers()
{
	int f0 = 0, f1 = 1;
	int f2 = f0 + f1;
	while (f2 < 1000000)
	{
		fibo[f2] = 1;
		f0 = f1;
		f1 = f2;
		f2 = f0 + f1;
	}
}

int main (void)
{
	generate_fibonacci_numbers();
	
	int T = read();
	while (T--)
	{
		int X = read(), Y = read();
		int cnt = 0;
		if (X <= Y)
		{
			for (int i = X; i <= Y; i++)
			{
				if (fibo[i])
					cnt++;
			}
		}
		else
		{
			for (int i = Y; i <= X; i++)
			{
				if (fibo[i])
					cnt++;
			}
		}
		if (cnt % 2)
			printf ("INVALID\n");
		else
			printf ("VALID\n");
	}
	
	
	return 0;
}
