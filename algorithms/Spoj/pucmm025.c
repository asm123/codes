#include <stdio.h>
#include <string.h>

int main (void)
{
	char num[250] = "\0";
	while (scanf ("%s", num) != EOF)
	{
		int count[10] = {0}, i = 0, sum = 0, s = 0;
		while (num[i])
		{
			count[num[i] - '0']++;
			s += (num[i] - '0');
			i++;
		}
// 		for (i = 0; i < 10; i++)
// 		  printf ("%d\t", count[i]);
// 		printf ("\n");
		int len = strlen (num), n = 0;
		if (len > 3)
		  for (i = len-3; num[i]; i++)
		    n = n * 10 + (num[i] - '0');
		else
		  for (i = 0; num[i]; i++)
		    n = n * 10 + (num[i] - '0');
		
		if (count[1] > 0)
		  sum += count[1];
		if (n % 2 == 0 && count[2] > 0)
		  sum += count[2];
		if (s % 3 == 0 && count[3] > 0)
		  sum += count[3];
		if (n % 4 == 0 && count[4] > 0)
		  sum += count[4];
		if ((num[len-1] == '5' || num[len-1] == '0') && (count[5] > 0))
		  sum += count[5];
		if (n % 2 == 0 && s % 3 == 0 && count[6] > 0)
		  sum += count[6];
		if (n % 8 == 0 && count[8] > 0)
		  sum += count[8];
		n = num[0] - '0';
		for (i = 1; num[i]; i++)
		{
			n = n * 3 + (num[i] - '0');
			n %= 7;
		}
		if (n == 0 && count[7] > 0)
		  sum += count[7];
		  
		if (s % 9 == 0 && count[9] > 0)
		  sum += count[9];
		
		printf ("%d\n", sum);
	}
	return 0;
}