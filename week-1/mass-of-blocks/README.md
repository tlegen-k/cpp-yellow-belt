# Tasks from week 1 of course

## C++ Yellow belt

This repository contains my solutions to tasks from week 1 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
 
There is a base of regions represented by a vector of Region structures:
'''cpp
struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};
'''
Here Lang is the language identifier:
'''cpp
enum class Lang {
  DE, FR, IT
};
'''
Write the FindMaxRepetitionCount function, which accepts the base of regions and determines the maximum number of repetitions (the number of occurrences of the same element) it contains. Two records (objects of type Region) are considered different if they differ in at least one field.

If all entries are unique, consider the maximum number of retries to be 1. If there are no entries, return 0. It is guaranteed that the int type is sufficient to store the response.
