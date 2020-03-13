/*
 * main.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: tlegenkamidollayev
 */




#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> temperatures(n);
  double sum = 0;
  for (double& temperature : temperatures) {
    cin >> temperature;
    sum += temperature;
  }

  double average = sum / n;
  vector<int> result_indices;
  for (int i = 0; i < n; ++i) {
    if (temperatures[i] > average) {
      result_indices.push_back(i);
    }
  }

  cout << result_indices.size() << endl;
  for (int result_index : result_indices) {
    cout << result_index << " ";
  }
  cout << endl;

  return 0;
}
