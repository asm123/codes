#include <stdio.h>

inline int read ()
{
	char c;
	int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

int main (void)
{
	int n;
	while ((n = read ()))
	{
		int a[n], stack[n], i, j, top = 0;
		for (i = 0; i < n; i++)
		  scanf ("%d", &a[i]);
		i = 0, j = 1;
		while (i < n)
		{
			if (a[i] == j)
			  j++;
			else 
			{
				while (top > 0 && stack[top] == j)
				{
					j++;
					top--;
				}
				top++;
				stack[top] = a[i];
			}
			i++;
		}
		while (top > 0 && stack[top] == j)
		{
			j++;
			top--;
		}
		if (top == 0)
		  printf ("yes\n");
		else
		  printf ("no\n");
	}
	return 0;
}