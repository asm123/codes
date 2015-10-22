#include <iostream>

using namespace std;

int min (int a, int b) { return (a < b) ? a : b; }

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		unsigned long long int K;
		cin >> N >> K;
		unsigned long long int count = 0;
		for (int i = 0; i < N; i++)
		{
			unsigned long long int x;
			cin >> x;
			unsigned long long int y = x / K;
			unsigned long long int z = x % K;
			if (y == 0)
				count += K - x;
			else
				count += min (z, K*(y+1) - x);
		}
		cout << count << endl;
	}
	
	return 0;
}
