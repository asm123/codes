#include <stdio.h>

int main (void)
{
	while (1)
	{
		int g, b;
		scanf ("%d%d", &g, &b);
		if (g == -1 && b == -1)
		  break;
		else
		{
			if (g == 0)
			  printf ("%d\n", b);
			else if (b == 0)
			  printf ("%d\n", g);
			else if (g == b)
			  printf ("1\n");
			else
			{
				int places, people;
				if (g > b) { places = b + 1; people = g; }
				else { places = g + 1; people = b; }
				if (people % places)
				  printf ("%d\n", people / places + 1);
				else
				  printf ("%d\n", people / places);
			}
		}
	}
  
	return 0;
}