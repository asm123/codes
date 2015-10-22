#include <stdio.h>

int main (void)
{
	float l;
	while (1)
	{
		scanf ("%f", &l);
		if (l == 0.00)
		  break;
		float sum = 0;
		int i = 1;
		while (sum <= l)
		{
			sum += (float)1/(i + 1);
			i++;
		}
		printf ("%d card(s)\n", i - 1);	
	}
	
	return 0;
}