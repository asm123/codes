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
	int t = read ();
	while (t--)
	{
		char expr[100], op = '+';
		int ans = 0, n = 0;
		while (scanf ("%s", expr) == 1)
		{
// 			printf ("%s\t%d\t", expr, ans);
			if (expr[0] >= 48 && expr[0] <= 57)
			{
				int i = 0;
				n = 0;
				while (expr[i])
				{
					n = n * 10 + (expr[i] - '0');
					i++;
				}
				switch (op)
				{
					case '+': ans += n; break;
					case '-': ans -= n; break;
					case '*': ans *= n; break;
					case '/': ans /= n; break;
				}
			}
			else
			{
				if (expr[0] == '=')
				{
					printf ("%d\n", ans);
					break; 
				}
				op = expr[0];
			}
// 			printf ("\n");
		}
	}
  
	return 0;
}