# Tasks from week 2 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 2 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Realize functions defined in header file
```cpp
{
    #pragma once
    #include <string>
    #include <vector>

    using namespace std;

    int Sum(int x, int y);
    string Reverse(string s);
    void Sort(vector<int>& nums);

};
}
```
You need to send a cpp-file containing the definitions of these functions.

Functions must add two numbers, reverse the string, and sort the vector of numbers in ascending order, respectively.

**How your code will be tested**

The automated testing system will add your cpp file to the project containing another cpp file with unit tests for all three functions, as well as the sum_reverse_sort.h file. Then it will build this project and, if the compilation is successful, it will run the resulting executable file. If it succeeds (that is, unit tests do not find errors in your implementation), then your submission will be counted.
