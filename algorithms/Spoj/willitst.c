#include <stdio.h>

int main (void)
{
	long long int n;
	
	scanf ("%lld", &n);

	while (n && n != 1)
	{
		if (n % 2) 
		{
			printf("NIE\n");
			return 0;
		}
		else
		{
			n /= 2;
		}
	}
	printf("TAK\n");
	return 0;
}