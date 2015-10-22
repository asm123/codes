#include <stdio.h>

int main (void)
{
	char str[10001];
	while (gets (str))
	{
		int i = 0, j;
		while (str[i])
		{
			if (str[i] != str[i+1])
			{
				printf ("1");
				for (j = i; str[j] && str[j] != str[j+1]; j++, i++)
				{
					if (str[j] == '1')
					  printf ("11");
					else
					  printf ("%c", str[j]);
				}
				printf ("1");
			}
			else
			{
				int len = 0;
				char cur = str[i];
				for (j = i; str[j] && str[j] == cur && len < 9; j++, i++, len++);
				printf ("%d%c", len, cur);
			}
		}
		
		printf ("\n");
	}
  
	return 0;
}