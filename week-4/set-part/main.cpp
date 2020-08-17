/*
 * main.cpp
 *
 *  Created on: Apr 17, 2020
 *      Author: tlegenkamidollayev
 */
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto result = find_if(
			begin(elements), end(elements),
			[border](const T& ind) {
				return (ind > border);
	});
	vector<T> answer;
	for (auto it = result; it != end(elements); ++it) {
		//cout << *it << " ";
		answer.push_back(*it);
	}
	return answer;
}


int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
