#include <iostream>

using namespace std;

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M, K;
		cin >> N >> M >> K;
		int files[101] = {0};
		for (int i = 1; i <= N; i++)
			files[i] = 0;
		for (int i = 0; i < M; i++)
		{
			int x;
			cin >> x;
			files[x]++;
		}
		for (int i = 0; i < K; i++)
		{
			int x;
			cin >> x;
			files[x]++;
		}
		int tracked_and_ignored = 0;
		int untracked_and_unignored = 0;
		for (int i = 1; i <= N; i++)
		{
			if (files[i] == 0)
				untracked_and_unignored++;
			else if (files[i] >= 2)
				tracked_and_ignored++;
		}
		cout << tracked_and_ignored << " " << untracked_and_unignored << endl;
	}
	
	return 0;
}
