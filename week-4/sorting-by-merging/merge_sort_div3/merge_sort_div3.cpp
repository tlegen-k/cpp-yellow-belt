/*
 * merge_sort_div3.cpp
 *
 *  Created on: Apr 21, 2020
 *      Author: tlegenkamidollayev
 */




/*
 * main.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: tlegenkamidollayev
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){

	if (range_end - range_begin < 2) {
		return;
	}
		vector<typename RandomIt::value_type> elements(range_begin, range_end);

		auto it_left = begin(elements) + elements.size()/3;
		auto it_right = it_left + elements.size()/3;

		MergeSort(begin(elements), it_left);
		MergeSort(it_left, it_right);
		MergeSort(it_right, end(elements));
		vector<typename RandomIt::value_type> temp;

		merge(begin(elements), it_left, it_left, it_right, back_inserter(temp));
		merge(begin(temp), end(temp), it_right, end(elements), range_begin);


//		merge(begin(elements), middle, middle, end(elements),range_begin);
}


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, -1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;

  vector<int> v1 = {3, 4, 8, 5, 4, 2, 0, 1, 3};
  MergeSort(begin(v1), end(v1));
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  vector<string> v2 = { "as","ty","tt", "aa", "asa", "lol"};
  	MergeSort(begin(v2), end(v2));
  	for (auto& x : v2) {
  		cout << x << " ";
  	}
  	cout << endl;

  return 0;
}
