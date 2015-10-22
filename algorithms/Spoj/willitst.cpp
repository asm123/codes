#include<stdio.h>

int main (void)
{
	long long int num, n;
	scanf("%lld", &num);
	
	if (num % 2)
	{
		printf("NIE\n");
	}
	else
	{
		n = 1;
		while(n <= num)
		{
			if(n == num)
			{
				printf("TAK\n");
				break;
			}
			n = n<<1;
		}
		if (n > num)
		{
			printf("NIE\n");
		}
	}
	return 0;
}
