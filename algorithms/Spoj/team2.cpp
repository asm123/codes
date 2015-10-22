using namespace std;

#include <stdio.h>
#include <algorithm>

int main (void)
{
	int n = 0;
	int a[4];
	
	while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) == 4)
	{
		sort (a, a + 4);
		printf ("Case %d: %d\n", ++n, a[3] + a[2]);
	}
	return 0;
}