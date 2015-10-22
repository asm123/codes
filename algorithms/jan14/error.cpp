#include <iostream>
#include <cstdio>
using namespace std;

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		char bin[1000000];
		scanf ("%s", bin);
		char p0 = '\0', p1 = '\0';
		int i = 0;
		while (bin[i])
		{
			if ((bin[i] == '0' && p1 == '1' && p0 == '0') || (bin[i] == '1' && p1 == '0' && p0 == '1'))
			{
				printf ("Good\n");
				break;
			}
			p0 = p1;
			p1 = bin[i];
			i++;
		}
		if (!bin[i])
			printf ("Bad\n");
	}
	return 0;
}
