/*
 * main.cpp
 *
 *  Created on: Apr 21, 2020
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
    char prefix) {
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
	string word = {prefix};
	auto lower = lower_bound(range_begin, range_end, word);

	auto next_letter = static_cast<char>(prefix + 1);
	std::string word_2 = {next_letter};

	auto upper = upper_bound(range_begin, range_end, word_2);
	return (make_pair(lower, upper));
}

/*
int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;

  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;

  return 0;
}
*/
