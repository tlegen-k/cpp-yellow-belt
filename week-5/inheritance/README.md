## Inheritance
Follow code is given:
```cpp
#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код

    const string Name;
};


class Dog {
public:
    // ваш код

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
```
Define to the end of the class body, observing the following requirements:

1. The Dog class must inherit from the Animal class.
2. The Dog class constructor must take a string parameter and initialize it to the Name field in the Animal class.
