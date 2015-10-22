#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[101];
	while (scanf ("%s", str) != EOF)
	{
		int len = strlen (str), cpp = 0, java = 0, i = 0, us[len], up[len], flag = 0;
		for (i = 0; i < len; i++)
		  us[i] = up[i] = 0;
		i = 0;
		while (str[i])
		{
			if (str[i] == '_')
			{
				if (java == 1 || i == 0 || str[i-1] == '_' || (i == (len-1)))
				{
					flag = 1;
					break;
				}
				else
				{
					cpp = 1;
					us[i] = 1;
				}
			}
			else if (str[i] >= 65 && str[i] <= 90)
			{
				if (cpp == 1 || i == 0)
				{
					flag = 1;
					break;
				}
				else
				{
					java = 1;
					up[i] = 1;
				}
			}
			i++;
		}
		if (flag)
		  printf ("Error!\n");
		else
		{
			if (java)
			{
				i = 0;
				while (str[i])
				{
					if (up[i])
					  printf ("_%c", str[i] + 32);
					else
					  printf ("%c", str[i]);
					i++;
				}
			}
			else if (cpp)
			{
				  i = 0;
				  while (str[i])
				  {
					if (us[i])
					{
						i++;
						if (str[i])
						  printf ("%c", str[i] - 32);
					}
					else
					  printf ("%c", str[i]);
					i++;
				  }
			}
			else
			  printf ("%s", str);
			printf ("\n");
		}
	}
	return 0;
}