#include <iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int main (void)
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int M[n][n];
	
	for (int i = 0; i < n; i++)
		M[i][i] = i;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[M[i][j-1]] > a[j])
				M[i][j] = M[i][j-1];
			else
				M[i][j] = j;
		}
	}
	
	int k;
	cin >> k;
	
	for (int i = 0; i < n-k+1; i++)
	{
		cout << a[M[i][i+k-1]] << " ";
	}
	cout << endl;
	
	return 0;
}
