# Tasks from week 1 of course

## C++ Yellow belt

This repository contains my solutions to tasks from week 1 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)

### Regions base
We have regions base presented by vector of Region structures:
```cpp
{
    struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};
}
```
There lang - language identificator:
```cpp
{
    enum class Lang {
    DE, FR, IT
};
}
```
Write a FindMaxRepetitionCount function that takes a region base and determines the maximum number of repetitions (the number of occurrences of the same element) it contains. Two records (objects of type Region) are considered different if they differ in at least one field.
```cpp
{
    int FindMaxRepetitionCount(const vector<Region>& regions);
}
```
If all records are unique, consider the maximum number of repetitions to be 1. If there are no records, return 0. It is guaranteed that int is sufficient to hold the response.
### Code example
```cpp
{
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
}
```
