#include <stdio.h>

int read ( int * location)
{
	register int digit;
	register int result = 0;

	while( (digit = getchar()) >= '0')
		result = (result << 3) + (result << 1) + digit - '0';

	*location = result;

	return 0;
}

int main()
{
	int sum_1 = 0, sum_2 = 0, p_1, p_2, winner, lead = 0, round;

	read (&round);

	while(round--)
	{
		read(&p_1);
		read(&p_2);
		p_1 = p_1 + sum_1;
		p_2 = p_2 + sum_2;
		if(p_1 > p_2 )
		{
			if( lead < ( p_1 - p_2 ) )
			{
				winner = 1;
				lead = p_1 - p_2;
			}

		}

		else if (p_2 > p_1)
		{
			if( lead < ( p_2 - p_1 ) )
			{
				winner = 2;
				lead = p_2 - p_1;
			}
		}

		sum_1 = p_1;
		sum_2 = p_2;
	}

	printf("%d %d\n", winner, lead);

	return 0;
}