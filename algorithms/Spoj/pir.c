#include <stdio.h>
#include <math.h>

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
	int t = read ();
	while(t--)
	{
		double u, v, w, U, V, W, u1, v1, w1, volsq, vol;
		scanf("%lf%lf%lf%lf%lf%lf", &u, &v, &w, &W, &V, &U);
		u1 = v*v + w*w - U*U;
		v1 = w*w + u*u - V*V;
		w1 = u*u + v*v - W*W;
		volsq = 4.0*u*u*v*v*w*w - u*u*u1*u1 - v*v*v1*v1 - w*w*w1*w1 + u1*v1*w1;
		vol = sqrt(volsq) / 12.0;
		printf("%.4lf\n", vol);
	}  
	return 0;
}