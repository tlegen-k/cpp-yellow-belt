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

class Rational {
public:
    Rational() {
    	num = 0;
    	denom = 1;
    }

    Rational(int numerator, int denominator) {
//    	cout << numerator << " " << denominator << endl;
    	int a=abs(numerator);
    	int b=abs(denominator);
    	int gcd = 1;
//    	cout << a << " " << b << endl;

    	while (a>0 && b>0)
    	{
    		if (a>b)
    		{
    			a=a%b;
    		}
    		else
    		{
    			b=b%a;
    		}
    	}

    	gcd = a+b;

    	num = numerator/gcd;
    	denom = denominator/gcd;

    	if ((num < 0 && denom < 0) || (num > 0 && denom < 0))
    	{
    		num = -num;
    		denom = -denom;
    	}
    	else if (numerator==0)
    	{
    		num = 0;
    		denom = 1;

    	}
/*    	cout << "GCD " << gcd << endl;
    	cout << "Num " << num << endl;
    	cout << "Denom " << denom << endl; */
    }

    int Numerator() const
    {
        // Реализуйте этот метод
    	return num;
    }

    int Denominator() const
    {
        // Реализуйте этот метод
    	return denom;
    }


private:
    // Добавьте поля
    int num;
    int denom;
};

void TestSimpleFraction() {
	AssertEqual(Rational(1,2).Numerator(), 1, "1/2 p");
	AssertEqual(Rational(1,2).Denominator(), 2, "1/2 q");
	AssertEqual(Rational(1,1000).Numerator(), 1, "1/1000 p");
	AssertEqual(Rational(1,1000).Denominator(), 1000, "1/1000 q");

}
void TestNegativeFraction() {
	{
	AssertEqual(Rational(-1,2).Numerator(), -1, "-1/2 p");
	AssertEqual(Rational(-1,2).Denominator(), 2, "-1/2 q");
	}
	AssertEqual(Rational(1,-2).Numerator(), -1, "1/-2 p");
	AssertEqual(Rational(1,-2).Denominator(), 2, "1/-2 q");
}
void TestPositiveFraction() {
	AssertEqual(Rational(-1,-2).Numerator(), 1, "-1/-2 p");
	AssertEqual(Rational(-1,-2).Denominator(), 2, "-1/-2 q");
	{
	AssertEqual(Rational(1,1).Numerator(), 1, "1/1 p");
	AssertEqual(Rational(1,1).Denominator(), 1, "1/1 q");
	}
	{
		AssertEqual(Rational(46784,246345).Numerator(), 46784, "46784");
		AssertEqual(Rational(46784,246345).Denominator(), 246345, "246345");
	}
}
void TestDefaultConstructor() {
	AssertEqual(Rational().Numerator(), 0, "default p");
	AssertEqual(Rational().Denominator(), 1, "default q");
	{
		AssertEqual(Rational(0,15).Numerator(), 0, "0/15 p");
		AssertEqual(Rational(0,15).Denominator(), 1, "0/15 q");
	}
}
void TestSimplifiedFraction() {
	AssertEqual(Rational(6,2).Numerator(), 3, "6/2 p");
	AssertEqual(Rational(6,2).Denominator(), 1, "6/2 q");
		AssertEqual(Rational(4,8).Numerator(), 1, "4/8 p");
		AssertEqual(Rational(4,8).Denominator(), 2, "4/8 q");
}

int main() {
	  TestRunner runner;
	  runner.RunTest(TestSimpleFraction, "1/2, 1/1000");
	  runner.RunTest(TestNegativeFraction, "-1/2, 1/-2");
	  runner.RunTest(TestPositiveFraction, "-1/-2");
	  runner.RunTest(TestDefaultConstructor, "default constructor");
	  runner.RunTest(TestSimplifiedFraction, "6/2");
	  // добавьте сюда свои тесты

	return 0;
}
