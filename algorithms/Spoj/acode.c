#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[5001];
	while (1)
	{
		scanf ("%s", str);
		int len = strlen (str);
		if (len == 1)
		{
			if (str[0] == '0')
			  break;
			printf ("1\n");
		}
		else
		{
			if (str[0] == '0')
			{
				printf ("0\n");
				break;
			}
			long long int dec[len], i;
			dec[0] = 1;
			if (str[0] > '2' || str[1] == '0')
			  dec[1] = 1;
			else if (str[0] == '1' && str[1] != '0')
			  dec[1] = 2;
			else if (str[0] == '2' && str[1] <= '6')
			  dec[1] = 2;
			else
			  dec[1] = 1;
			
			for(i = 2; i < len; ++i) 
			{
				if (str[i] == '0' && str[i-1] == '0')
				{
					dec[len-1] = 0;
					break;
				}
				if (str[i] == '0')
				  dec[i] = dec[i-2];
				else
				{
					if (str[i-1] == '1' || (str[i-1] == '2' && str[i] <= '6'))
					  dec[i] = dec[i-1] + dec[i-2];
					else if (str[i] != '0')
					  dec[i] = dec[i-1];
				}
			}
			
			printf ("%lld\n", dec[len-1]);
		}
		
	}
	return 0;
}