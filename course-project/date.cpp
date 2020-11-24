#include <iomanip>
#include <sstream>
#include <stdexcept>

#include "date.h"

using namespace std;

Date::Date(const string &date) : Year(0), Month(0), Day(0) {
    istringstream is = istringstream(date);
    is >> Year;
    is.get();
    is >> Month;
    is.get();
    is >> Day;
}
Date::Date(const Date &other) : Year(other.GetYear()), Month(other.GetMonth()),
                                Day(other.GetDay()){}
int Date::GetYear() const {
    return Year;
}

int Date::GetMonth() const {
    return Month;
}

int Date::GetDay() const {
    return Day;
}

Date ParseDate(istream& is) {
    int year;
    int month;
    int day;
    is >> year;
    is.get();
    is >> month;
    is.get();
    is >>day;
    return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date) {
	os << setfill('0') << setw(4) << date.GetYear() << '-';
	os << setfill('0') << setw(2) << date.GetMonth() << '-';
	os << setfill('0') << setw(2) << date.GetDay();
	return os;
}

bool operator==(const Date& date_1, const Date& date_2) {
	return ( (date_1.GetYear() == date_2.GetYear()) &&
			(date_1.GetMonth() == date_2.GetMonth()) &&
			(date_1.GetDay() == date_2.GetDay()) );
}
bool operator!=(const Date& date_1, const Date& date_2) {
    return !(date_1 == date_2);
}

bool operator<(const Date &first, const Date &second) {
    if (first.GetYear() == second.GetYear()) {
        if (first.GetMonth() == second.GetMonth()) {
            return first.GetDay() < second.GetDay();
        }
        return first.GetMonth() < second.GetMonth();
    }
    return first.GetYear() < second.GetYear();
}

bool operator<=(const Date& date_1, const Date& date_2) {
	return (date_1 < date_2) || (date_1 == date_2);
}

bool operator>(const Date& date_1, const Date& date_2) {
	return date_2 < date_1;
}

bool operator>=(const Date& date_1, const Date& date_2) {
	return (date_1 > date_2) || (date_1 == date_2);
}

string Date::str() const
{
    ostringstream ost;
    ost << setw(4) << setfill('0') << Year << '-'
        << setw(2) << Month << '-' << setw(2) << Day;
    return ost.str();
}

