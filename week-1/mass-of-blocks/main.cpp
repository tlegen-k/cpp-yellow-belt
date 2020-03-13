/*
 * main.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: tlegenkamidollayev
 */


#include <iostream>
#include <vector>

using namespace std;
struct Dimensions {
	uint64_t width;
	uint64_t height;
	uint64_t depth;
};

int main() {
  uint64_t n; //number of blocks
  uint64_t density; // density of blocks

  cin >> n;
  cin >> density;
  vector<uint64_t> masses(n); //masses of each block
  vector<Dimensions> size_of_blocks(n);
  //cout << size_of_blocks.size() << endl;

  for (uint64_t i = 0; i < n; ++i) {
	  cin >> size_of_blocks.at(i).width >> size_of_blocks.at(i).height >> size_of_blocks.at(i).depth;
  }
  uint64_t total_mass=0;

  for (uint64_t i=0; i < n; ++i) {
	   masses.at(i) = density * size_of_blocks.at(i).width * size_of_blocks.at(i).height * size_of_blocks.at(i).depth;
	 //  cout << masses.at(i);
	   total_mass += masses.at(i);
	  // cout << "total mass at i " << total_mass << endl;
  }

  cout << total_mass << endl;

  return 0;
}
