## Reference to element
Implement the GetRefStrict templated function that takes as input: map and a key value k. If there is no element by key k in the collection, then the function must throw a runtime_error exception, otherwise return a reference to the element in the collection.

An example of using the function
```cpp
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
}
```
