using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>

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
	int n = read (), i;
	for (i = 1; i <= n; i++)
	{
		string str;
		int m = read () - 1;
		cin >> str;
		cout << i << " " << str.substr (0, m) << str.substr (m + 1) << endl;;
	}
	return 0;
}