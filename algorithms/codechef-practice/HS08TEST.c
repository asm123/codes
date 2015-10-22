#include <stdio.h>

int main(void)
{
	int x;
	float y;
	scanf("%d%f", &x, &y);

	
	if(x < y && x % 5 == 0)
	{
		float z = (float)x + 0.50;
		if(y > z)
		  y = y-z;
	}
	printf("%.2f\n", y);
	return 0;
}