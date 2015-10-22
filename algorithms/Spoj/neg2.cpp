using namespace std;

#include <stdio.h>
#include <string>

int main (void)
{
	int n;
	scanf ("%d", &n);
	if (n == 0)
	  printf ("0\n");
	else
	{
		string bin;
		while (n != 0)
		{
			int r = n % -2;
// 			printf ("%d, %d\t\t", n, r);
			n /= -2;
// 			printf ("%d, %d\t\t", n, r);
			if (r == 0)
			{
// 				printf ("%d, %d\t\t", n, r);
				bin = "0" + bin;
// 				printf ("%d, %d\t\t", n, r);
			}
			else
			{
				if (r == -1)
				{
					r = 1;
					n++;
				}
				bin = "1" + bin;
			}
// 			printf ("%d, %d\n", n, r);
		}
		printf ("%s\n", bin.c_str());
	}
  
	return 0;
}