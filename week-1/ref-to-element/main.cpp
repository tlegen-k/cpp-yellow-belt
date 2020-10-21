#include <iostream>
#include <exception>
#include <map>
#include <system_error>
#include <string>
#include <stdexcept>
using namespace std;

// pre-definition of template function
template<typename K, typename V> V& GetRefStrict(map<K, V>& m, K key);

// definition of function
template<typename K, typename V>
V& GetRefStrict(map<K, V>& m, K key) {
	if (m.count(key) == 0 ){
		throw runtime_error("runtime error");
	}
	else {
		return (m[key]);
	}
}

int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // cout newvalue

	return 0;
}
