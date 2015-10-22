#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) 
{
	char * roman = (char *) malloc (sizeof (char) * 101);
    int q = num / 1000;
    if (q >= 1)
	{
		int i;
		for (i = 0; i < q; i++)
			strcat (roman, "M");
		num = num % 1000;
	}
	q = num / 500;
	if (q >= 1)
	{
		if (num < 900)
		{
			int i;
			strcat (roman, "D");
			for (i = 0; i < q-5; i++)
				strcat (roman, "C");
			num = num % 500;
		}
		else
		{
			strcat (roman, "CM");
			num = num % 900;
		}
	}
	q = num / 100;
	if (q >= 1)
	{
		if (q <= 3)
		{
			int i;
			for (i = 0; i < q; i++)
				strcat (roman, "C");
		}
		else if (q == 4)
			strcat (roman, "CD");
		num = num % 100;
	}
	q = num / 50;
	if (q >= 1)
	{
		if (num < 90)
		{
			int i;
			strcat (roman, "L");
			for (i = 0; i < q-5; i++)
				strcat (roman, "X");
			num = num % 50;
		}
		else
		{
			strcat (roman, "XC");
			num = num % 90;
		}
		
	}
	q = num / 10;
	if (q >= 1)
	{
		if (q <= 3)
		{
			int i;
			for (i = 0; i < q; i++)
				strcat (roman, "X");
		}
		else if (q == 4)
			strcat (roman, "XL");
		num = num % 10;
	}
	q = num / 5;
	if (q >= 1)
	{
		if (num < 9)
		{
			int i;
			strcat (roman, "V");
			for (i = 0; i < q-5; i++)
				strcat (roman, "I");
			num = num % 5;
		}
		else
		{
			strcat (roman, "IX");
			num = num % 9;
		}	
	}
	if (num >= 1)
	{
		if (num <= 3)
		{
			int i;
			for (i = 0; i < num; i++)
				strcat (roman, "I");
		}
		else if (num == 4)
			strcat (roman, "IV");
	}
	return roman;
}

int main (void)
{
	int x;
	scanf ("%d", &x);
	printf ("%s\n", intToRoman(x));
	return 0;
}
