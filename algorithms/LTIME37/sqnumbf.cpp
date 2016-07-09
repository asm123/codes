#include <iostream>

using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
	unsigned long long int rem;
	if (b == 0) 
		return a;
	while(true) {
		rem = a % b;
		if (rem == 0)
			break;
		a = b;
		b = rem;
	}
	return b;
}

int main(void) {
	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;
		/*
		unsigned long long int numbers[N];
		for (int i = 0; i < N; i++) {
			cin >> numbers[i];
		}
		bool found = false;
		unsigned long long int g = 1;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				g = gcd(numbers[i], numbers[j]);
				if (g > 1) {
					found = true;
					break;
				}	
			}
			if (found)
				break;
		}
		cout << g << endl;
		*/
		unsigned long long int X = 1, a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			X *= a;
		} 
		unsigned long long int n = 2;
		while (true) {
			unsigned long long int rem = X % (n * n);
			if (rem == 0) {
				cout << n << endl;
				break;
			}
			n++;
		}
	}

	return 0;
}
