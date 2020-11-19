### Separation into words
Write a SplitIntoWords function that splits a string into words by spaces.
```cpp
vector<string> SplitIntoWords(const string& s);
```
It is guaranteed that:

- the string is not empty;
- the line consists only of Latin letters and spaces;
- the first and last characters of the line are not spaces;
- the line does not contain two spaces in a row.

### Hint

The following way of solving the problem is recommended:

- search for the next space using the find algorithm;
- create the next word using the string constructor over two iterators.

### Code example
```cpp
int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
```
