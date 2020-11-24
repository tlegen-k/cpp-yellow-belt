#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
    Date() : Year(0), Month(0), Day(0) {}
    Date(int year, int month, int day) : Year(year), Month(month), Day
    (day) {}
    explicit Date(const string &);
    Date(const Date&);
    ~Date() = default;
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    string str() const;
private:
    int Year;
    int Month;
    int Day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);
bool operator==(const Date& date_1, const Date& date_2);
bool operator<(const Date& date_1, const Date& date_2);
bool operator>(const Date& date_1, const Date& date_2);
bool operator!=(const Date& date_1, const Date& date_2);
bool operator<=(const Date& date_1, const Date& date_2);
bool operator>=(const Date& date_1, const Date& date_2);
