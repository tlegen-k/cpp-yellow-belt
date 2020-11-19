## Demographic stats
In this task, you need to calculate various demographics for a group of people. The person is represented by the Person structure:
```cpp
struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};
```
The Gender type is defined as follows:
```cpp
enum class Gender {
  FEMALE,
  MALE
};
```
You need to write a PrintStats function that takes a vector of people, calculates and outputs the median age for each of the following groups of people:

- all people;
- all women;
- all men;
- all busy women;
- all unemployed women;
- all busy men;
