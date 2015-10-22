#include <iostream>
#include <cmath>

using namespace std;

int main (void)
{
	unsigned long long n, m, a;
	cin >> n >> m >> a;
	unsigned long long no = ceil (1.0 * n / a) * ceil (1.0 * m / a);
	cout << no << endl;
	return 0;
}

