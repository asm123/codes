using namespace std;

#include <iostream>
#include <cstdio>

struct trie
{
	struct trie *child[26];
	bool end;
	trie () 
	{ 
		for (int i = 0; i < 26; i++ ) 
			child[i] = NULL; 
		end = false; 
	}
} root;


void insert (char *word)
{
	struct trie *node = root;
	int i = 0;
	while (word[i])
	{
		int d = word[i] - 'a';
		if (!node -> child[d])
			node -> child[d] = new trie;
		node = node -> child[d];
	}
	node -> end = true;
}


int main (void)
{
	root = new trie;
	
	int n;
	scanf ("%d", &n);
	while (n--)
	{
		char word[25];
		scanf ("%s", word);
		insert (word);
	}
	int k;
	scanf ("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		char word[25];
		scanf ("%s", word);
		printf ("Case #%d:\n", i);
	}
	
	return 0;
}
