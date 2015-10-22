#include <iostream>

using namespace std;

class BIT
{
	int *tree, size;
}

int main (void)
{
	int N, Q;
	cin >> N >> Q;
	unsigned long long int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	while (Q--)
	{
		int op, x, y;
		unsigned long long int v;
		cin >> op >> x >> y >> v;
		if (op == 1) // add
		{
			
		}
		else if (op == 2) // multiply
		{
			
		}
		else if (op == 3) // initialize
		{
			
		}
		else // get range sum
		{
			
		}
	}
	return 0;
}
