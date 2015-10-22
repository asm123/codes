#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main (void)
{
	int T;
	scanf ("%d", &T);
	while (T--)
	{
		int L, D, C;
		double S;
		scanf ("%d%d%lf%d", &L, &D, &S, &C);
		bool alive = false;
		while (--D)
		{
			if (ceil (S) >= L)
			{
				printf ("ALIVE AND KICKING\n");
				alive = true;
				break;
			}
			S = S + (S * C);
		}
		if (!alive)
		{
			if (ceil (S) >= L)
				printf ("ALIVE AND KICKING\n");
			else
				printf ("DEAD AND ROTTING\n");
		}
	}
	return 0;
}
