Write a templated function MergeSort that takes two iterators of the template type RandomIt and sorts the range they specify using merge sort. It is guaranteed that:

- iterators of type RandomIt are similar in functionality to vector and string iterators, that is, they can be compared using the <, <=,> and> = operators, as well as subtracted and added with numbers;
- sorted objects can be compared using the <operator.
```cpp
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);
```
## Part 1. Implementation with splitting into 2 parts
Algorithm

The classic merge sort algorithm looks like this:

- If the range contains less than 2 elements, exit the function.
- Create a vector containing all the elements of the current range.
- Split the vector into two equal parts. (In this task, it is guaranteed that the length of the transmitted range is a power of two, so that the vector can always be split into two equal parts.)
- Call the MergeSort function from each half of the vector.
- Using the merge algorithm, merge the sorted halves, writing the resulting sorted range instead of the original.

You must implement exactly this algorithm and no other: the testing system will check that you are doing exactly these actions with the elements.
### Hint

To create a vector containing all the elements of the current range (item 2 of the algorithm), it is necessary to be able to recognize the type of elements to which it points by the type of the iterator. If the RandomIt iterator belongs to a standard container (vector, string, set, dictionary ...), the underlying type can be obtained using the typename expression RandomIt :: value_type. Thus, it is guaranteed that you can create a vector in step 2 as follows:
```cpp
vector<typename RandomIt::value_type> elements(range_begin, range_end);
```
## Part 2. Implementation with splitting into 3 parts

Implement merge sort by splitting the range into 3 equal parts, not 2. The length of the original range is guaranteed to be a power of 3.

Accordingly, paragraphs 3-5 of the algorithm should be replaced with the following:

- Divide the vector into 3 equal parts.
- Call the MergeSort function from each part of the vector.
- Merge the first two-thirds of the vector using the merge algorithm, saving the result to a temporary vector using back_inserter.
- Merge the temporary vector from the previous item with the last third of the vector from item 2, writing the resulting sorted range instead of the original one.
