#include <iostream>
#include <cstdio>

int max (int a, int b)
{
	return (a ^ ((a ^ b) & -(a < b)));
}

int main (void)
{
	while (true)
	{
		int A[10001], B[10001];
		int a, b, sum_A = 0, sum_B = 0, sum = 0;
	
		scanf ("%d", &a);
		if (a == 0)
			break;
		for (int i = 0; i < a; i++)
			scanf ("%d", &A[i]);
		scanf ("%d", &b);
		for (int i = 0; i < b; i++)
			scanf ("%d", &B[i]);
		int i = 0, j = 0;
		while (i < a && j < b)
		{
			if (A[i] == B[j])
			{
				sum += max (sum_A, sum_B) + A[i];
				sum_A = 0;
				sum_B = 0;
				i++;
				j++;
			}
			else if (A[i] < B[j])
			{
				sum_A += A[i];
				i++;
			}
			else
			{
				sum_B += B[j];
				j++;
			}
		}
		while (i < a)
		{
			sum_A += A[i];
			i++;
		}
		while (j < b)
		{
			sum_B += B[j];
			j++;
		}
		sum += max (sum_A, sum_B);
		printf ("%d\n", sum);
	}
	return 0;
}
