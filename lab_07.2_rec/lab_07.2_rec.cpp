#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

int** make_arr(int rows) {
	return new int* [rows];
}

void make_rows(int** arr, int rows, int cols, int index) {
	if (index != rows) {
		arr[index] = new int[cols];
		make_rows(arr, rows, cols, index + 1);
	}
}

void fill_arr(int** arr, int rows, int cols, int low, int high, int r=0, int c=0) {
	if (r != rows) {
		if (c != cols) {
			arr[r][c] = low + rand() % (high - low + 1);
			fill_arr(arr, rows, cols, low, high, r, c + 1);
		}
		else {
			fill_arr(arr, rows, cols, low, high, r + 1, 0);
		}
	}
}

void print_arr(int** arr, int rows, int cols, int r=0, int c=0) {
	if (r != rows) {
		if (c != cols) {
			cout << setw(4) << arr[r][c];
			print_arr(arr, rows, cols, r, c + 1);
		}
		else {
			cout << endl;
			print_arr(arr, rows, cols, r + 1, 0);
		}
	}
	else {
		cout << endl;
	}
}

void max_on_1st_diag(int** arr, int n, int& _max, int index=1) {
	if (index != n) {
		if (_max < arr[index][index]) {
			_max = arr[index][index];
		}
		max_on_1st_diag(arr, n, _max, index + 1);
	}
}

int main() {
	srand(time(NULL));

	int n, _max;
	cout << "n = "; cin >> n;

	int** arr = make_arr(n);
	make_rows(arr, n, n, 0);
	fill_arr(arr,n,n,-10,10);
	print_arr(arr, n, n);
	_max = arr[0][0];
	max_on_1st_diag(arr, n, _max);
	cout << "max = " << _max << endl;
}
