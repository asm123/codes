using namespace std;

#include <stdio.h>

inline short int read ()
{
	char c;
	short int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

int main (void)
{
	short int t = read ();
	while (t--)
	{
		short int candle[10], index = 1, min = 9;
		for (short int i = 0; i < 10; i++)
		{
			candle[i] = read ();
			if (candle[i] < min || (candle[i] == min && index == 0))
			{
				min = candle[i];
				index = i;
			}
		}
		if (index == 0)
		  printf ("1");
		for (short int i = 0; i <= candle[index]; i++)
		  printf ("%d", index);
		printf ("\n");
		
	}
}