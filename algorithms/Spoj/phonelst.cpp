using namespace std;

#include <iostream>
#include <cstdio>

struct TrieNode
{
	struct TrieNode * child[10];
	bool end;
	TrieNode ()
	{
		for (int i = 0; i < 10; i++)
			child[i] = NULL;
		end = false;
	}
};

bool insert (struct TrieNode * root, char * num)
{
	struct TrieNode * temp = root;
	int i = 0;

	while (num[i])
	{
		if (temp -> end)
			return false;
		int d = num[i] - '0';
		if (!temp -> child[d])
			temp -> child[d] = new TrieNode;
		temp = temp -> child[d];
		i++;
	}
	temp -> end = true;
	for (i = 0; i < 10; i++)
	{
		if (temp -> child[i])
			return false;
	}
	return true;
}


int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		struct TrieNode * root = new TrieNode;
		int n;
		scanf ("%d", &n);
		bool consistent = true;
		while (n--)
		{
			char num[15];
			scanf ("%s", num);
			if (consistent)
			{
				if (!insert (root, num))
					consistent = false;
			}
		}
		if (consistent)
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}
