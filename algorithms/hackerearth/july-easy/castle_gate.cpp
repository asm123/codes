#include <iostream>
#define MAX 2001

using namespace std;

int main(void)
{
    int count[MAX] = {0};
    for (int i = 1; i < MAX; i++) {
    	for (int j = 1; j < MAX; j++) {
    		int x = i ^ j;
    		if (x < MAX) {
    			count[x]++;	
    		}
    		
    	}
    }
    for (int i = 1; i < MAX; i++) {
    	count[i] += count[i-1];
    }
    
    
    
    int t;
    cin >> t;
    while (t--) {
    	int N;
    	cin >> N;
    	cout << count[N] << endl;
    }
    return 0;
}
