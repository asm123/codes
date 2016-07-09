#include <iostream>

#define MAX 502

using namespace std;

int getGCD(int a, int b) {
	if (a == 0)
		return b;
	return getGCD(b % a, a);
}

int main(void) {
	
	int N;
	cin >> N;
	int a[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	
	int dp[MAX][MAX];
	for (int i = 1; i <= N; i++) {
		dp[i][a[i]] = 1;
		for (int j = i-1; j >= 1; j--) {
			if (a[j] < a[i]) {
				for (int k = 1; k <= 100; k++) {
					int g = getGCD(k, a[i]);
					dp[i][g] += dp[]
				}
			}
		}
	}
	
	
	return 0;
}
