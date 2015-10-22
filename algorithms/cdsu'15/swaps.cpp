#include <cstdio>
#include <cstring>

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
	int T = read();
	while (T--)
	{
		char str[1000000];
		int len = strlen (str);
		int count[1000000];
		scanf ("%s", str);
		if (str[0] == '0')
			count[0] = 1;
		else
			count[0] = -1;
		for (int i = 1; str[i]; i++)
		{
			if (str[i] == '1')
				count[i] = count[i-1] - 1;
			else
				count[i] = count[i-1] + 1;
		}
		int lowest = 1000000;
		int highest = -1000000;
		int lowestIndex = 0;
		int highestIndex = len - 1;
		
		for (int i = 0; str[i]; i++)
		{
			if (count[i] <= lowest)
			{
				lowest = count[i];
				lowestIndex = i;
			}
			if (count[i] >= highest)
			{
				highest = count[i];
				highestIndex = i;
			}
		}
		lowestIndex += 1;
		int sum_one = 0;
		int sum_zero = 0;
		for (int i = 0; str[i] && i < lowestIndex; i++)
		{
			if (str[i] == '0')
				sum_zero++;
			else
				sum_one++;
		}
		for (int i = lowestIndex; str[i] && i <= highestIndex; i++)
		{
			if (str[i] == '0')
				sum_one++;
			else
				sum_zero++;
		}
		for (int i = highestIndex + 1; str[i]; i++)
		{
			if (str[i] == '0')
				sum_zero++;
			else
				sum_one++;
		}
		printf ("%d\n", sum_one);
	}
	return 0;
}
