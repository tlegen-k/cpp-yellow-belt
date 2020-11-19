### Set part
Write a templated function FindGreaterElements that takes a set of elements objects of type T and another border object of type T, and returns a vector of all elements of the set greater than border in ascending order.
```cpp
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border);
```
### Code example
```cpp
int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
```
