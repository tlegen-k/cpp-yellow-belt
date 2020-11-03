# Tasks from week 2 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 2 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Tests for class Rational

The Rational class is a rational number and has the following interface
```cpp
{
class Rational {
    public:
    Rational();
    Rational(int numerator, int denominator);

    int Numerator() const;
    int Denominator() const;
};
}
```
The list of requirements for implementing the interface of the Rational class:

- The default constructor should create a fraction with numerator 0 and denominator 1.
- When constructing a Rational object with p and q parameters, p / q reduction must be performed.
- If p / q is negative, then the Rational (p, q) object must have a negative numerator and a positive denominator.
- If p / q is positive, then the Rational (p, q) object must have a positive numerator and denominator (note the case of Rational (-2, -3)).
- If the numerator of the fraction is zero, then the denominator must be 1.

Develop a set of unit tests that validate the implementation of the Rational class. There is no need to test the case where the denominator is zero.

You can get started with a template that contains our unit test framework and a template for a Rational class.
You can get started with a template that contains our unit test framework and a class template [test_rational.cpp](./test_rational.cpp).
