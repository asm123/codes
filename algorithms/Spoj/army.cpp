using namespace std;

#include <iostream>
#include <queue>
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
		int ng = read (), nm = read ();
		priority_queue < int, vector <int>, greater <int> > g;
		priority_queue < int, vector <int>, greater <int> > m;
		for (int i = 0; i < ng; i++)
		  g.push (read ());
		for (int i = 0; i < nm; i++)
		  m.push (read ());
		
		while (!(g.empty () || m.empty ()))
		{
			if (m.top () <= g.top ())
			  m.pop ();
			else
			  g.pop ();
		}
		if (g.empty ())
		  printf ("MechaGodzilla\n");
		else if (m.empty ())
		  printf ("Godzilla\n");
		else
		  printf ("uncertain\n");
	}
	
	return 0;
}