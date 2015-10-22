using namespace std;

#include <iostream>
#include <stdio.h>
#include <stack>

int main (void)
{
	char str[2001];
	int t = 0;
	while (1)
	{
		scanf ("%s", str);
		if (str[0] == '-')
		  break;
		
		int op = 0;
		stack <char> s;
		
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '{')
			  s.push (str[i]);
			else
			{
				if (!s.empty ())
				{
					s.pop ();
				}
				else
				{
					s.push ('{');
					op++;
				}
			}
		}
		
		if (!s.empty ())
		{
			op += s.size () / 2;
		}
		
		printf ("%d. %d\n", ++t, op);
	}
	
	return 0;
}