using namespace std;

#include <iostream>
#include <cstdio>

int main (void)
{
	int power[12] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
	
	int t;
	scanf ("%d", &t);
	
	while (t--)
	{
		char c;
		int n = 0;
		
		while ((c = getchar_unlocked ()) < 48);
		n += (c - '0');
		
		while ((c = getchar_unlocked ()) >= 48)
		  n = n * 10 + (c - '0');
		
		int count = 0;
		for (int i = 0; i < 12 && power[i] <= n; i++)
		  count += n / power[i];
		printf ("%d\n", count);
	}
  
	return 0;
}