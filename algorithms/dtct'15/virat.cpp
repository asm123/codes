#include <iostream>
#include <cstdio>

using namespace std;

int min (int a, int b) { return (a < b) ? a : b; }

int main (void)
{
	int n, minX = 101;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		minX = min (x, minX);
	}
	cout << minX << endl;
	return 0;
}
