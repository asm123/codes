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
		int k = read (), flag = 0, stem = 1; // Stem: Total no. of stems possible at the given level
		
		while (k--)
		{
			int leaves = read (); // Leaves: No. of leaves at the given level
			if (leaves > stem)
			{
				flag = 1;
				break;
			}
			stem = (stem - leaves) * 2; //No. of stems possible at the next level
		}
		if (flag || stem)
		  printf ("No\n");
		else
		  printf ("Yes\n");
	}
	return 0;
}