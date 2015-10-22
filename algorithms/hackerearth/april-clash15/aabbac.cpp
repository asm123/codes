#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char * strrev (char * str)
{
	int n = strlen (str);
	char * rev = (char *) malloc (sizeof(char) * (n+1));
	int i = 0, j = n-1;
	while (str[i])
	{
		rev[j] = str[i];
		i++;
		j--;
	}
	rev[n] = '\0';
	return rev;
}

void getSequence(char * sequence, char * newString)
{
	strcat (sequence, strrev(sequence));
	strcat (sequence, newString);
}

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		char strings[N][1000];
		for (int i = 0; i < N; i++)
			cin >> strings[i];
		char * sequence = strings[0];
		for (int i = 1; i < N; i++)
			getSequence(sequence, strings[i]);
		for (int i = 0; i < M; i++)
		{
			int x;
			cin >> x;
			cout << sequence[x];
		}
		cout << endl;
	}
	
	return 0;
}
