#include <iostream>

using namespace std;

int main (void) {
	int N, M;
	cin >> N >> M;
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	
	int max_so_far = 0, max_ending_here = 0;
	int j = 0;
	for (int i = 0; i < N; i++) {
		if (max_ending_here + a[i] > M) {
			max_so_far = max(max_ending_here, max_so_far);
			max_ending_here -= a[j];
			i--;
			j++;
		}
		else if (max_ending_here + a[i] == M) {
			max_so_far = M;
			max_ending_here -= a[j];
			i--;
			j++;
		}
		else {
			max_ending_here += a[i];
		}
	}
	max_so_far = max(max_so_far, max_ending_here);
	cout << max_so_far << endl;
	return 0;
}
