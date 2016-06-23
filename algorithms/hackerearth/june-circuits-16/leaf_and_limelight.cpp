#include <iostream>
#include <cmath>

using namespace std;

int getSum(unsigned long long int sums[1000001], unsigned int length, unsigned long long int N) {
	unsigned long long int modulus = 1000000009;
	unsigned long long int totalSum = 0;
	
	for (unsigned long long int i = N; i >= 0; i -= 2) {
		if (i < length) {
			totalSum = (totalSum % modulus + sums[i] % modulus) % modulus;
			break;
		}
		else {
			unsigned long long int leftTopCorner = ((unsigned long long int)pow(i,2));
			unsigned long long int rightTopCorner = (leftTopCorner - (i-1));
			
			unsigned long long int rightBottomCorner = (rightTopCorner - (i-1));
			unsigned long long int leftBottomCorner = (rightBottomCorner - (i-1));
			
			unsigned long long int topSums = (leftTopCorner + rightTopCorner) % modulus;
			unsigned long long int bottomSums = (leftBottomCorner + rightBottomCorner) % modulus;
			
			totalSum = (totalSum % modulus + (topSums + bottomSums) % modulus) % modulus;
		}
	}
	
	return totalSum;
}

int main(void) {
	unsigned long long int modulus = 1000000009;
	
	unsigned long long int maxNumber = 1000000;
	unsigned long long int sums[1000001];
	
	sums[1] = 1;
	sums[2] = 10;
	
	for (unsigned long long int i = 3; i <= maxNumber; i++) {
		unsigned long long int leftTopCorner = ((unsigned long long int)pow(i,2));
		unsigned long long int rightTopCorner = leftTopCorner - (i-1);
		
		unsigned long long int rightBottomCorner = rightTopCorner - (i-1);
		unsigned long long int leftBottomCorner = (rightBottomCorner - (i-1)) % modulus;
		
		unsigned long long int topSums = (leftTopCorner % modulus + rightTopCorner % modulus) % modulus;
		unsigned long long int bottomSums = (leftBottomCorner % modulus + rightBottomCorner % modulus) % modulus;
		
		sums[i] = (sums[i-2] % modulus + (topSums + bottomSums) % modulus) % modulus;
	}
	int T;
	cin >> T;
	while(T--) {
		long long int N;
		cin >> N;
		
		cout << getSum(sums, maxNumber+1, N) << endl;
		
	}
	
	return 0;
}
