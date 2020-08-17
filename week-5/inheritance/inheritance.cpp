/*
 * inheritance.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: tlegenkamidollayev
 */
#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код
	Animal(const string& name)
	: Name(name) {

	}
    const string Name;
};


class Dog : public Animal{
public:
    // ваш код
	Dog(const string& name) : Animal(name) {
	}
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
	Dog dog("barbos");
	dog.Bark();
	return 0;
}



