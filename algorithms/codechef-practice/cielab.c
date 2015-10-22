#include <stdio.h>

int main (void)
{
	int a, b;
	scanf ("%d%d", &a, &b);
	int n = a - b;
	char num[6] = "00000";
	int i = -1;
	while (n > 0)
	{
		i++;
		num[i] = n % 10 + 48;
		n /= 10;
	}
	if (num[i] == '9')
	  num[i] = '8';
	else
	  num[i]++;
	while (i >= 0)
	{
		printf ("%c", num[i]);
		i--;
	}
	printf ("\n");
	return 0;
}