#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int X, N;
		cin >> X >> N;
		long long int count = 0;
		int found[2001] = {0};
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			if (X >= n) {
				count += found[X-n];
			}
			found[n] += 1;
		}
		cout << t << ". " << count << endl;
	}
	
	
	return 0;
}
