using namespace std;

#include <cstdio>
#include <cstring>

int main (void)
{
	int t;
	scanf ("%d", &t);
	
	while (t--)
	{
		char a[40010], b[40010];
		scanf ("%s%s", a, b);
		int count1 [26] = {0}, count2[26] = {0};
		int i, k;
		for (i = 0; a[i]; i++)
		{
			int c = a[i] - 'a';
			count1[c]++;
		}
		for (i = 0; b[i]; i++)
		{
			int c = b[i] - 'a';
			count1[c]++;
		}
		int n;
		scanf ("%d", &n);
		
		for (k = 0; k < n; k++)
		{
			char str[40010];
			scanf ("%s", str);
			for (i = 0; str[i]; i++)
			{
				int c = str[i] - 'a';
				count2[c]++;
			}
		}
		bool flag = false;
		for (i = 0; i < 26; i++)
		{
			if (count2[i] > count1[i])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			printf ("NO\n");
		else
			printf ("YES\n");
	}
	
	return 0;
}
