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
		if (N == 1)
		{
			if (a[0] < 2)
				cout << "-1" << endl;
			else
				cout << "2" << endl;
		}
		else
		{
			bool flag = false;
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				if (a[i] >= 2)
					sum += 2;
				else	
			}
		}
		
	}
	
	return 0;
}
