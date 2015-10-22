#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		unsigned long long int a[N];
		for (int i = 0; i < N; i++)
			cin >> a[i];
		sort(a, a+N);
		unsigned long long int sum = 0;
		unsigned long long int modValue = 1000000007;
		for (int i = 0; i < N; i++)
			for (int j = 0, k = i+1; j <= N-i-2 && k < N; j++, k++)
				sum += (((a[k]-a[i]) % modValue) * ((long long int)pow(2,j) % modValue)) % modValue;
		cout << sum << endl;
	}
	
	return 0;
}
