#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Person {
public:
	Person(const string & name, const string & person_type) : Name(name), Person_type(person_type){
	}
	virtual void Walk(const string& destination) {
		cout << Person_type << ": " << GetName() << " walks to: " << destination << endl;
	}
	string GetName() {
		return Name;
	}
	string GetType() {
		return Person_type;
	}
	~Person() = default;
private:
	const string Name;
	const string Person_type;
};

class Student : public Person {
public:

    Student(const string & name, const string & favouriteSong) :
    Person(name, "Student"), FavouriteSong(favouriteSong) { }

    void Learn() {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    virtual void Walk(const string& destination) override {
        cout <<  GetType()<< GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() {
        cout << GetType() << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};

class Teacher : public Person {
public:

    Teacher(string name, string subject) :
    Person(name, "Teacher"), Subject(subject) {
    }

    void Teach() {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(string name) :
    Person(name, "Policeman") {
    }
    void Check(Person & p) {
    	cout << GetType() << ": " << GetName() << " checks " << p.GetType() << ". " <<
    			p.GetType() << "'s name is: " << p.GetName() << endl;
    }
};

void VisitPlaces(Person& p, const vector<string>& places) {
	for (auto place : places) {
		p.Walk(place);
	}
}
int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    p.Check(t);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
