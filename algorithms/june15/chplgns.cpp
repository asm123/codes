#include <iostream>
#include <vector>

using namespace std;

class Polygon
{
	public:
		vector <int> coordinates;
		
};

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		unsigned long long int sum = 0;
		unsigned long long int prev = 0;
		for (int i = 0; i < N; i++)
		{
			unsigned long long int M;
			cin >> M;
			if (M > prev)
				sum += M-prev;
			prev = M;
		}
		cout << sum << endl;
	}
}
