using namespace std;

#include <iostream>
#include <stdio.h>
#include <stack>

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
		char exp[400];
		scanf ("%s", exp);
		stack <char> s;
		for (int i = 0; exp[i]; i++)
		{
			switch (exp[i])
			{
			  case '(': continue;
				    break;
			  case ')': if (!s.empty ())
				    {
					printf ("%c", s.top ());
					s.pop ();
				    }
				    break;
			  case '+': case '-': case '*': case '/': case '^': s.push (exp[i]); break;
			  default: printf ("%c", exp[i]);
			}
		}
		printf ("\n");
	}
	return 0;
}