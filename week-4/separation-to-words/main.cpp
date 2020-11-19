#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	auto it_begin = s.begin();
	auto it_end = find(s.begin(), s.end(), ' ');
	
	while (it_end != s.end()) {
		string word(it_begin, it_end);
		result.push_back(word);
		it_begin=it_end+1;
		it_end=find(it_begin, s.end(), ' ');
	}
	string word(it_begin, it_end);
	result.push_back(word);
	return result;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

   s = "C Cpp Java Python Lolik London Italy france";

    words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
      if (it != begin(words)) {
        cout << "/";
      }
      cout << *it;
    }
    cout << endl;
  return 0;
}
