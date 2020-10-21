#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;

// advance definition template functions

template <typename T> T Sqr(const T& x);
template <typename First, typename Second> pair <First, Second> Sqr(const pair<First, Second>& p);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);
template <typename V> vector<V> Sqr(const vector<V>& v);

// definition template functions
template <typename T>
T Sqr(const T& x) {
	return (x * x);
}

template <typename First, typename Second>
pair <First, Second> Sqr(const pair<First, Second>& p) {
	return (make_pair(Sqr(p.first), Sqr(p.second)));
}

template <typename V>
vector<V> Sqr(const vector<V>& v) {
	vector<V> result;
	for (auto& i : v) {
		result.push_back(Sqr(i));
	}
	return (result);
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
	map<Key, Value> result;
	for (const auto& i : m){
		result[i.first] = Sqr(i.second);
	}
	return (result);
}



int main() {

	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
