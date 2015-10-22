#include <iostream>

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
		unsigned long long int sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		unsigned long long int x[N], x_sum;
		x_sum = sum / (N-1);
		for (int i = 0; i < N; i++)
			x[i] = x_sum - a[i];
		for (int i = 0; i < N; i++)
			cout << x[i] << " ";
		cout << endl;
	}
	return 0;
}
