# Tasks from week 2 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 1 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Tests for class Person

In the first course "White Belt on C ++" we had the task "Names and surnames - 1" [https://www.coursera.org/learn/c-plus-plus-white/programming/4FQn4/imiena-i-familii-1]. In it, it was necessary to develop a Person class that maintains the history of changes by a person to his last name and first name. In this task, you need to develop unit tests for implementing the Person class. When designing your tests, consider the limitations of the First and Last Name - 1 task condition on the Person class.

You can get started with a template that contains our unit test framework and a class template [test_person.cpp](./test_person.cpp).

### Conditions for task "Name and surnames - 1"
Implement a human class that maintains a person's history of changes to their last name and first name.
```cpp
{
    class Person {
    public:
      void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
      }
      void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
      }
      string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
      }
    private:
      // приватные поля
};
}
```
Consider that no more than one surname change and no more than one name change can occur each year. At the same time, over time, more and more facts from a person's past may be discovered, therefore, the years in successive calls to the ChangeLastName and ChangeFirstName methods are not required to increase.

It is guaranteed that all first and last names are non-empty.

The string returned by the GetFullName method must contain the person's first and last name, separated by a single space, as of the end of the given year.

- If no surname or first name changes have occurred by this year, return the "Incognito" string.
- If there was a last name change for the given year, but there was no name change, return "last_name with unknown first name".
- If there was a name change for the given year, but there was no last name change, return "first_name with unknown last name".

**Note**

Before uploading your file, make sure it doesn't contain the Person class. Otherwise, you will get a compilation error. Our testing system can ignore functions in files (therefore, for example, in the "Tests for IsPalindrom function" task, it is not necessary to remove the IsPalindrom function), but it cannot do this for classes.
