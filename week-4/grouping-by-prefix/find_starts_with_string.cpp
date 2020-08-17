/*
 * find_starts_with_string.cpp
 *
 *  Created on: Apr 23, 2020
 *      Author: tlegenkamidollayev
 */

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
	// go through each element to find that starts with prefix.
	// Binary search algorithm
//	RandomIt left = range_begin;
//	RandomIt right = range_end;
	//RandomIt  middle;// middle of range
	/* while (left <= right) {
		auto middle = (right - left)/2;
		auto element = *middle;
		if ( element[0] < prefix) {
			left = middle + 1;
		}
		else if (element[0] > prefix) {
			right = middle - 1;
		}
		else {
			return element[0];
		}
	} */
	if (prefix.empty() || range_begin == range_end) {
		return make_pair(range_begin, range_end);
	}

	auto lower = lower_bound(range_begin, range_end, prefix);
	string boundary = prefix;
	++boundary[boundary.size() - 1];

	auto upper = lower_bound(range_begin, range_end, boundary);
	return (make_pair(lower, upper));
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}
