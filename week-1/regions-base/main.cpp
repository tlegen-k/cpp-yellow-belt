#include <vector> // std::vector
#include <string> // std::string
#include <map> // std::map
#include <iostream> // std::cout
#include <algorithm> // std::count
using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

//- Overloading comparison operator for *max_element method of vector
bool operator<(const Region& lhs, const Region& rhs) {
	  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
	      tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}
//- Overloading equal operator for count method of vector
bool operator==(const Region& lhs, const Region& rhs) {
	if ((lhs.std_name == rhs.std_name) && (lhs.parent_std_name == rhs.parent_std_name)
			&& (lhs.names == rhs.names) && (lhs.population == rhs.population) ) {
		return true;
	}
	else {
		return false;
	}
}
int FindMaxRepetitionCount(const vector<Region>& regions)
{
	int size_of_map = regions.size();
	if (size_of_map == 0) {
		return 0;
	}
	else {
		vector<int> repetitions(size_of_map);
		for (int i = 0; i < size_of_map; ++i) {
			Region region = regions.at(i);
			//repetitions.at(i) = regions.count(region);
			repetitions[i] = count(regions.begin(), regions.end(), region);
		}
		//cout << "The highest number of repetitions is " << max_element(repetitions.begin(), repetitions.end());
		// realisation below will likely to fail for task requirements as *max_element will point at last
		// element if vector is empty
		int indicator_of_largest = *max_element(repetitions.begin(), repetitions.end());
		return repetitions.at(indicator_of_largest);
	}
}

int main() {
	cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      },
	  }) << endl;

	  cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Toulouse",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          31
	      },
	  }) << endl;
	return 0;
}
