#include <iostream>

using namespace std;

int** getMultiplication(int a[][5], int b[][2], int a_rows, int a_cols, int b_rows, int b_cols) {
	if (a_cols != b_rows)
		return NULL;
	int **c = new int*[a_rows];
	for (int i = 0; i < a_rows; i++)
		c[i] = new int[b_cols];
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			c[i][j] = 0;
			for (int k = 0; k < b_rows; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

int main(void) {
	int a[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
	int b[5][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
	
	int **c = getMultiplication(a, b, 2, 5, 5, 2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}
	
	return 0;
}
