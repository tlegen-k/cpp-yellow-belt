
#ifndef QUERY_H_
#define QUERY_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q);


#endif /* QUERY_H_ */
