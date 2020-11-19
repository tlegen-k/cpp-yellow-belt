#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
	string second;
	int size = str.size();
	if (size == 0) {
		return true;
	}
	else if (size == 1) {
		return true;
	}
	else {
		for ( int i=size; i>0; --i)
		{
			second += str[i-1];
		}

		if (!second.compare(str))
		{
			return true;

		}
		else
		{
			return false;
		}
	}
}
void TestEmptyString()	{
	string w;
	w="";
	AssertEqual(IsPalindrom(w), true, "empty string");
}
void TestOneSymbolString() {
	AssertEqual(IsPalindrom("w"), true, "one symbol string");
	Assert (IsPalindrom ("1"), "One symbol string is palindrome");
	Assert (IsPalindrom ("-"), "One symbol string is palindrome");
	Assert (IsPalindrom ("&"), "One symbol string is palindrome");
}
void TestNonPalindrom() {
	AssertEqual(IsPalindrom("word"), false, "word");
	AssertEqual(IsPalindrom("lo"), false, "lo");
	AssertEqual(IsPalindrom("lasfopaopaof"), false, "lasfopaopaof");
	AssertEqual(IsPalindrom("___AbA__"), false, "___AbA__");
	Assert(!IsPalindrom(" ABCCBA"), " ABCCBA");
	Assert(!IsPalindrom("ABCCBA "), "ABCCBA ");
	Assert(!IsPalindrom("ABCCB A"), "ABCCB A");
	Assert(!IsPalindrom("ABCcBA"), "ABCcBA");
	Assert(!IsPalindrom("XabbaY"), "XabbaY is not a palindrome");
	Assert(!IsPalindrom("ab"), "ab");
	Assert(!IsPalindrom("778"), "778");
    Assert(!IsPalindrom(" lev e  l   "),"Is not palindrome");
    Assert(!IsPalindrom("mada m"),"Is not palindrome");


	AssertEqual(IsPalindrom("A  L L A"), false, "A  L L A");
	AssertEqual(IsPalindrom("mada m"), false, "mada m");
	AssertEqual(IsPalindrom(" weew   "), false, " weew   ");
	AssertEqual(IsPalindrom("   weew "), false, "   weew ");
}
void TestPolindrom() {
	AssertEqual(IsPalindrom("wow"), true, "wow");
	AssertEqual(IsPalindrom("lolol"), true, "lolol");
	AssertEqual(IsPalindrom("___AbA___"), true, "___AbA___");
	AssertEqual(IsPalindrom("a a"), true, "a a");
    Assert(IsPalindrom("l e v e l"),"Is palindrome");
    Assert(IsPalindrom("l  e  v  e  l"),"Is palindrome");
    Assert(IsPalindrom("  "), "  ");

	AssertEqual(IsPalindrom("f f ff f f"), true, "f f ff f f");
	AssertEqual(IsPalindrom("f f f f f"), true, "f f f f f");

}
int main() {
  TestRunner runner;
  runner.RunTest(TestEmptyString, "test empty string");
  runner.RunTest(TestOneSymbolString, "test one symbol string");
  runner.RunTest(TestNonPalindrom, "test non palindroms");
  runner.RunTest(TestPolindrom, "test polindroms");
  return 0;
}
