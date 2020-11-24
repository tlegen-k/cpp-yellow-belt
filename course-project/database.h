#pragma once

#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include "date.h"

using namespace std;

class Database {
public:
    Database() = default;
    void Add(const Date&, const string&);
    vector<pair<Date, string>> FindIf(const function<bool(const Date&, const string& )>&) const;
    int RemoveIf(const function<bool(const Date&, const string& )>&);
    pair<Date, string> Last(const Date&) const;
    void Print(ostream&) const;
private:
    map<Date, set<string>> date_events;
    map<Date, vector<string>> date_events_ordered;
};
ostream& operator<<(ostream&, const pair<Date, string>&);