/*
 * main.cpp
 *
 *  Created on: Apr 14, 2020
 *      Author: tlegenkamidollayev
 */
#include "sum_reverse_sort.h"
#include "test_runner.h"
void TestSum() {
	AssertEqual(Sum(3,5), 8, "3+5=8");
}
void TestReverse() {
	AssertEqual(Reverse("mom"), "mom", "mom");
	AssertEqual(Reverse("moloko"), "okolom", "moloko");
}
void TestSort() {
	vector<int> r{10, 9, 8};
	vector<int> result{8, 9, 10};
	AssertEqual(Sort(r)), result, "8 9 10");
}
int main() {
	  TestRunner runner;
	  runner.RunTest(TestSum, "Test sums");
	  runner.RunTest(TestReverse, "Test reverse");
	return 0;
}

