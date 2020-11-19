#include "query.h"

using namespace std;
istream& operator >> (istream& is, Query& q) {
	string input;
	is >> input;
	if (input == "NEW_BUS")
	{
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stop_count=0;
		cin >> stop_count;
		q.stops.resize(stop_count);
		for (auto& stop : q.stops) {
			is >> stop;
		}
	}
	else if (input == "BUSES_FOR_STOP")
	{
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (input == "STOPS_FOR_BUS")
	{
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (input == "ALL_BUSES")
	{
		q.type = QueryType::AllBuses;
	}

  return (is);
}
