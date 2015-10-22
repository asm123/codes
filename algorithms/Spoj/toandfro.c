#include <stdio.h>
#include <string.h>

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
	int col;
	while ((col = read ()))
	{
		char str[201];
		scanf ("%s", str);
		int i, j;
		int len = strlen (str);
		int rows = len / col;
		char msg[rows][col];
		
		int start, end = 0;
		
		for (i = 0; i < rows; i++)
		{
			int k = 0;
		  
			start = end;
			end = start + col;
			
			if (i % 2 == 0)
			{
				for (j = start; j < end; j++)
				{
					msg[i][k] = str[j];
					k++;
				}
			} 
			else
			{
				for (j = end - 1; j >= start; j--)
				{
					msg[i][k] = str[j];
					k++;
				}
			}
			
		}
		for (j = 0; j < col; j++)
		{
			for (i = 0; i < rows; i++)
			  printf ("%c", msg[i][j]);
		}
		printf ("\n");
	}
	return 0;
}