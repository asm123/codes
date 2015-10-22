#include <stdio.h>
#include <string.h>

int main (void)
{
	int n;
	scanf ("%d", &n);
	if (n == 0)
	  printf ("0\n");
	else
	{
		char bin[100] = "", temp[100] = "";
		while (n != 0)
		{
			int r = n % -2;
			n /= -2;
			if (r == 0)
			{
				strcpy (temp, bin);
				strcpy (bin, "0");
				strcat (bin, temp);
			}
			else
			{
				if (r == -1)
				{
					r = 1;
					n++;
				}
				strcpy (temp, bin);
				strcpy (bin, "1");
				strcat (bin, temp);
			}
		}
		printf ("%s\n", bin);
	}
  
	return 0;
}