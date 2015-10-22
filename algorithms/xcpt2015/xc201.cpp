#include <cstdio>

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

int maxDist(char* s)
{
	int max_len = 1;
	int cur_len = 1;
	int visited[26];
	for (int i = 0; i < 26; i++)
		visited[i] = -1;
	visited[s[0] - 'a'] = 0;
	for (int i = 1; s[i]; i++)
	{
		int prev_index = visited[s[i] - 'a'];
		if (prev_index == -1 || i - cur_len > prev_index)
			cur_len++;
		else
		{
			if (cur_len > max_len)
				max_len = cur_len;
			cur_len = i - prev_index;
		}
		visited[s[i] - 'a'] = i;
	}
	if (cur_len > max_len)
		max_len = cur_len;
	return max_len;
}

int main (void)
{
	int T = read();
	while (T--)
	{
		char city[100000];
		scanf ("%s", city);
		printf ("%d\n", maxDist(city));
	}
	return 0;
}
