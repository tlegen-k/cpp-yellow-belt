#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
	auto result = find_if(
			begin(numbers), end(numbers),
			[](const int& number) {
				return number < 0;
	});
	for (auto it = result; it != begin(numbers); ) {
		cout << *(--it) << " ";
	}
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
