## Find nearest element
Write a FindNearestElement function that, for a set of integers numbers and a given number border, returns an iterator to the element of the set closest to border. If there are multiple nearest elements, return the iterator to the smallest one.
```cpp
set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border);
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел
```
