#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> number(n);
	for (int i = 0; i < n; ++i) {
		number.at(i) = n-i;
		cout << number[i] << " ";
	}
	cout << endl;
	while (prev_permutation(number.begin(), number.end())) {
		for (int i = 0; i < n; ++i) {
				cout << number[i] << " ";
			}
		cout << endl;
	}
	return 0;
}
