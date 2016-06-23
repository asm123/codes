#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)  {
		int N;
		cin >> N;
		unsigned long long int a[N];
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		if (N == 0) {
			cout << "Case " << t << ": 0" << endl;
			continue;
		}
		unsigned long long int dp[N];
		dp[0] = a[0];
		if (N > 1) {
			dp[1] = max(dp[0], a[1]);
			for (int i = 2; i < N; i++) {
				dp[i] = max(a[i] + dp[i-2], dp[i-1]);
			}
		}
		cout << "Case " << t << ": " << dp[N-1] << endl;
	}
	
	return 0;
}
