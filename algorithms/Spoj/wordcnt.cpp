#include <cstdio>
#include <cstring>

#define T(x) strtok(x, " \n\r\t")

char line[32768];

int main (void)
{
	int t; 
	scanf ("%d\n", &t);
	while (t--)
	{
		fgets (line, 32768, stdin);
                int count = 1, len, max = 0, prev = -1;
                for (char * p = T (line); p != NULL; p = T (NULL))
		{
			len = strlen(p);
			if (len == prev) 
			  count++;
			else 
			  count = 1;
			if (count > max) 
			  max = count;
			prev = len;
                }
                printf ("%d\n", max);
        }
        return 0;
}