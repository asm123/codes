#include <stdio.h>
#include <string.h>

int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		char op1[1000], op2[1000], ans[1000], sp1, plus, sp2, sp3, eq, sp4;
		int n1 = 0, n2 = 0, n = 0;
		scanf ("%s%c%c%c%s%c%c%c%s", op1, &sp1, &plus, &sp2, op2, &sp3, &eq, &sp4, ans);
		int len1 = strlen (op1), len2 = strlen (op2), len3 = strlen (ans);
		int i = 0, flag = 0;
// 		printf ("%s %s %s\n", op1, op2, ans);
		while (op1[i] >= 48 && op1[i] <= 57)
		{
			n1 = n1 * 10 + (op1[i] - '0');
			i++;
		}
		if (i < len1)
		{
			flag = 1;
			i += 7;
			while (op1[i])
			{
				n1 = n1 * 10 + (op1[i] - '0');
				i++;
			}
		}
		i = 0;
		while (op2[i] >= 48 && op2[i] <= 57)
		{
			n2 = n2 * 10 + (op2[i] - '0');
			i++;
		}
		if (flag == 0)
		{
			if (i < len2)
			{
				flag = 2;
				i += 7;
				while (op2[i])
				{
					n2 = n2 * 10 + (op2[i] - '0');
					i++;
				}
			}
		}
		i = 0;
		while (ans[i] >= 48 && ans[i] <= 57)
		{
			n = n * 10 + (ans[i] - '0');
			i++;
		}
		if (flag == 0)
		{
			if (i < len3)
			{
				flag = 3;
				i += 7;
				while (ans[i])
				{
					n = n * 10 + (ans[i] - '0');
					i++;
				}
			}
		}
		
		if (flag == 0)
		  printf ("%d + %d = %d\n", n1, n2, n);
		else if (flag == 1)
		  printf ("%d + %d = %d\n", n - n2, n2, n);
		else if (flag == 2)
		  printf ("%d + %d = %d\n", n1, n - n1, n);
		else
		  printf ("%d + %d = %d\n", n1, n2, n1 + n2);
	}
	return 0;
}