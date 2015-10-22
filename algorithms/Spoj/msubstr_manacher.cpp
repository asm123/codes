using namespace std;

#include <iostream>
#include <string>

string preprocess (string s)
{
	int n = s.length ();
	string T = "^";	
	for (int i = 0; i < n; i++)
		T += "#" + s.substr (i, 1);
	T += "#$";	
	return T;
}

int min (int x, int y) { return ((x < y) ? x : y); }

void printNumberOfMirrorStrings (string s)
{
	string T = preprocess (s);
	int n = T.length ();
	
	int * P = new int [n];
	int * max_arr = new int [n];
	
	int C = 0, R = 0;
	
	for (int i = 0; i < n; i++)
	{
		P[i] = 0;
		max_arr[i] = 0;
	}
	
	for (int i = 1; i < n-1; i++)
	{
		int i_mirror = C - (i - C);
		
		P[i] = (R > i) ? min (R - i, P[i_mirror]) : 0;
		
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
		
		if (i + P[i] > R)
		{
			C = i;
			R = i + P[i];
		}
	}
	
	int max = 0;
	for (int i = 1; i < n-1; i++)
	{
		if (P[i] > max)
			max = P[i];
		max_arr[P[i]]++;
	}
	
	cout << max << " " << max_arr[max] << endl;
	
	delete [] P;
	delete [] max_arr;
}

int main (void)
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		printNumberOfMirrorStrings (s);
	}
	return 0;
}
