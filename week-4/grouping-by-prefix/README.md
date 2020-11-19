## Part 1. Grouping by symbol

Write the FindStartsWith function:

- accepting a sorted set of strings as iterators range_begin, range_end and one prefix character;
- returning a range of strings starting with prefix as a pair of iterators.
```cpp
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix);
```
If the resulting range is empty, its bounds should point to the place in the container where you can insert any line starting with the prefix character without breaking the sort order (similar to the equal_range algorithm). It is guaranteed that strings only consist of lowercase Latin letters and the prefix symbol is also a lowercase Latin letter.

The search should be done at logarithmic complexity — for example, using a binary search.
### Hint

You can add or subtract numbers to characters (char), thus obtaining the next or previous letters in alphabetical order. For example, for string s, the expression --s [0] will replace its first letter with the previous one.

Note that the expression 'a' + 1 is int and therefore you may need to cast it to char using static_cast.
## Part 2. Grouping by prefix

Write a more universal version of the FindStartsWith function that accepts an arbitrary string consisting of lowercase Latin letters as a prefix.
```Cpp
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix);
```
