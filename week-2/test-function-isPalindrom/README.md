# Tasks from week 2 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 1 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Tests for fucntion IsPalindrom

In this task, you need to develop a set of unit tests for the function
```cpp
{
bool IsPalindrom(const string& s);
}
```
This function checks if string s is a palindrome. A palindrome is a word or phrase that reads equally from left to right and right to left. Examples of palindromes: madam, level, wasitacaroracatisaw

Design a suite of unit tests that will accept correct implementations of IsPalindrom and reject incorrect ones. In doing so, keep in mind that the correct implementation of the function:

- treats an empty string as a palindrome;
- considers a single character string as a palindrome;
- performs regular character comparison for equality, without ignoring any characters, including whitespace.

When designing your tests, consider what mistakes you can make when implementing the IsPalindrom function. Examples of errors:

- the first or last character is ignored;
- comparison of the corresponding characters is completed not in the middle of the line, but earlier;
- spaces are ignored

You can get started with a template that contains our unit test framework and the IsPalindrom function template [test_palindrome.cpp](./test_palindrome.cpp).
