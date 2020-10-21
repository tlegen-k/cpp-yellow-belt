#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "sum_reverse_sort.h"
using namespace std;

int Sum(int x, int y) {
	return x+y;
}

string Reverse(string s) {
	string result;
	for (int i=s.size(); i > 0; i--) {
		result.push_back(s[i-1]);
	}
	return (result);

}
void Sort(vector<int>& nums) {

	sort(nums.begin(), nums.end(), [] (int i, int j) {
		return ( (i) < (j));
	});

}
