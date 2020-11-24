#include "database.h"
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;
void Database::Add(const Date &date, const string &event) {
    if (date_events[date].count(event) != 0) {}
    else
    {
        date_events[date].insert(event);
        date_events_ordered[date].emplace_back(event);
    }
}
vector<pair<Date, string>> Database::FindIf(const function<bool(const Date&, const string& )> &predicate) const {
    vector<pair<Date, string>> entries;
    for (const auto & item : date_events_ordered)
    {
        for (const auto & it : item.second)
        {
            if (predicate(item.first, it))
            {
                entries.emplace_back(pair<Date, string>(item.first, it));
            }
        }
    }
    return entries;
}

int Database::RemoveIf(const function<bool(const Date&, const string& )> &predicate) {
    int deletedEventsNumber = 0;
    vector<Date> empty_dates_ordered;

    //- Delete satisfying elements from ordered structure
    for (auto & item : date_events_ordered)
    {
        int size_init = item.second.size();
        //- Move all elements satisfying predicate to the first half of vector
        auto it_ = std::stable_partition(item.second.begin(), item.second.end(),
                [&](string& event) {return predicate(item.first,event);});

        vector<string> to_delete_set;

        to_delete_set.insert(to_delete_set.begin(), item.second.begin(), it_);

        item.second.erase(item.second.begin(), it_);

        deletedEventsNumber += size_init - item.second.size();

        for (auto item_set : to_delete_set)
        {
            date_events[item.first].erase(item_set);
        }

        if (item.second.empty())
        {
            date_events.erase(item.first);
            empty_dates_ordered.push_back(item.first);
        }
    }

    for (auto empty_dates : empty_dates_ordered)
    {
        date_events_ordered.erase(empty_dates);
    }

    return deletedEventsNumber;
}


pair<Date, string> Database::Last(const Date &date) const {
    if (date_events_ordered.empty())
    {
        throw invalid_argument(date.str());
    }
    auto it = date_events_ordered.upper_bound(date);
    if (it != date_events_ordered.begin())
    {
        it = prev(it);
        return make_pair(it->first, it->second.back());
    }
    else
    {
        throw invalid_argument("There is no last element");
    }
}

void Database::Print(ostream &os) const {
    for (const auto & item : date_events_ordered)
    {
        for (const auto & it : item.second)
        {
            os << item.first << ' ' << it << endl;
        }
    }
}

ostream & operator<<(ostream &os, const pair<Date, string> &pair) {
    os << pair.first << ' ' << pair.second;
    return os;
}