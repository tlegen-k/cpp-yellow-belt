# Tasks from week 1 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 1 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Everything squared

Implement a Sqr templated function that works not only for numbers but also for containers. The function should return a copy of the original container, modifying it as follows:

     for vector, elements need to be squared;
     for map, only values need to be squared, not keys;
     for pair, you need to square each element of the pair.
```cpp
{
    // Пример вызова функции
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
}
```
Output should be
```cpp
{
    vector: 1 4 9
    map of pairs:
    4 4 4
    7 16 9
}
```
The function should work correctly not only for containers consisting of numbers, but also for complex objects, for example, vectors of dictionaries of pairs of numbers.

For successful delivery of the solution, it is necessary to make a preliminary declaration of template functions before all template functions.

An example of a preliminary declaration of a template function
```cpp
{
    // Предварительное объявление шаблонных функций
    template<typename T> T FuncA(T x);
    template<typename T> void FuncB(T x);

    // Объявляем шаблонные функции
    template <typename T>
    T FuncA(T x) { /*...*/ }

    template <typename T>
    void FuncB(T x) { /*...*/ }
}
```
