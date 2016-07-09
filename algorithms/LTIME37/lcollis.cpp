#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		int count[M] = {0};
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < M; j++) {
				if (str[j] == '1')
					count[j]++;
			}
		}
		int sum = 0;
		for (int i = 0; i < M; i++) {
			if (count[i] > 1)
				sum += count[i] * (count[i]-1) / 2;
		}
		cout << sum << endl;
	} 
	
	return 0;
}
