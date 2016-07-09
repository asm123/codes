#include <iostream>

using namespace std;

int main(void) {
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		float avg = 0;
		bool failed = false, fullScore = false;
		for (int i = 0; i < N; i++) {
			int s;
			cin >> s;
			avg += s;
			if (s == 2) {
				failed = true;
			}
			else if (s == 5) {
				fullScore = true;
			}
		}
		if (failed || !fullScore) {
			cout << "No" << endl;
		}
		else {
			avg /= N;
			if (avg >= 4.0) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	
	return 0;
}
