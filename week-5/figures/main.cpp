/*
 * main.cpp
 *
 *  Created on: Apr 29, 2020
 *      Author: tlegenkamidollayev
 */
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
//#include <math.h>
#include <cmath>
#include <sstream>

using namespace std;

class Figure {
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
	virtual ~Figure()=default;
	//virtual ~Figure() {}
private:

};

class Triangle : public Figure {
public:
	Triangle(const double& a, const double& b, const double& c) :
		a_(a), b_(b), c_(c) {}
	virtual string Name() override {
		return name_;
	}
	virtual double Perimeter() override {
		return a_ + b_ + c_;
	}
	virtual double Area() override {
		double p; //half perimeter
		p = (a_ + b_ + c_) / 2.0;
		return static_cast<double>(sqrt(p * (p - a_) * (p - b_) * (p - c_)));
	}
//	virtual ~Triangle() = default
private:
	string name_ = "TRIANGLE";
	double a_; //3 sides of triangle
	double b_;
	double c_;

};

class Rect : public Figure {
public:
	Rect(const double& a, const double& b) :
		a_(a), b_(b) {}
	virtual string Name() override {
		return name_;
	}
	virtual double Perimeter() override {
		return (a_ + b_) * 2;
	}
	virtual double Area() override {
		return a_ * b_;
	}
//	virtual ~Rect() = default
private:
	string name_ = "RECT";
	double a_; //sides of rectangle
	double b_;

};

class Circle : public Figure {
public:
	Circle(const double& r) :
		r_(r) {}
	virtual string Name() override {
		return name_;
	}
	virtual double Perimeter() override {
		return 2.0 * 3.14 * r_;
	}
	virtual double Area() override {
		return 3.14 * pow(r_,2);
	}
//	virtual ~Circle() = default;
private:
	string name_ = "CIRCLE";
	double r_; //raidus of circle
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
	string input;
	is >> input;
	shared_ptr<Figure> figure;
	if (input == "RECT") {
		double a, b;
		is >> a >> b;
		figure = make_shared<Rect>(a, b);
	}
	else if (input == "TRIANGLE") {
		double a, b, c;
		is >> a >> b >> c;
		figure = make_shared<Triangle>(a, b, c);
	}
	else if (input == "CIRCLE") {
		double r;
		is >> r;
		figure = make_shared<Circle>(r);
	}
	return figure;
}
//std::string test { R"(
//ADD RECT 2 3
//ADD TRIANGLE 3 4 5
//ADD RECT 10 20
//ADD CIRCLE 5
//PRINT
//)" };
//std::istringstream input(test);

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
