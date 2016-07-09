#include <iostream>

using namespace std;

int getGCD(int a, int b) {
	if (a == 0)
		return b;
	return getGCD(b % a, a);
}

int main(void) {
	
	int N;
	cin >> N;
	int a[N], gcd[N][N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			gcd[i][j] = getGCD(a[i], a[j]);
		}
	}
	
	// find number of increasing subsequences
	int dp[N], g[N];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		g[i] = 0;
		for (int j = 0; j < i; j++) {
			if(a[i] > a[j]) {
				dp[i] += dp[j];
			}
		}
	}
	
	for (int i = N-1; i >= 0; i--) {
		for (int j = i-1; j >= 0; j--) {
			if (gcd[i][j] == 1) {
				g[i] += dp[i] - dp[j];
			}
			
		}
	}
	
	for (int i = 0; i < N; i++) {
		sum += g[i];
		cout << a[i] << "," << g[i] << endl;
	}
	
	
	cout << sum << endl;
	
	
	return 0;
}
