/*
 * main.cpp
 *
 *  Created on: Apr 21, 2020
 *      Author: tlegenkamidollayev
 */
#include <set>
#include <iostream>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
	// iterator pointing to first element that is last of not less elements
	auto first_not_less = numbers.lower_bound(border);

	// if set is empty or no elements >= border then point to begin of set
	if (first_not_less == numbers.begin()) {
		return first_not_less;
	}
	// points to the last elements that less than border
	auto last_less = prev(first_not_less);

	// if every item in set is less than border then point to last of set
	if (first_not_less == end(numbers)) {
		return last_less;
	}
	// otherwise search for closest element to border
	bool is_left = (border - *last_less <= *first_not_less - border);
	return is_left ? last_less : first_not_less;
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
