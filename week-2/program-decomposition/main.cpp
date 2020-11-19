#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

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

struct BusesForStopResponse {
	vector<string> buses; //vector to hold buses for specified stop
};

//output operator to print all buses for specified stop
ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
      os << "No stop" << endl;
    } else {
      for (const auto& bus : r.buses) {
        os << bus << " ";
      }
      os << endl;
    }

    return (os);
}

struct StopsForBusResponse {
	string bus;
	vector<pair<string, vector<string>>> stops_for_bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if ( r.stops_for_bus.empty()) {
		os << "No bus" << endl;
	}
	else {
		for (const auto& stop_and_bus : r.stops_for_bus) {
			os << "Stop " << stop_and_bus.first << ":";
			if (stop_and_bus.second.size() == 1) {
				os << " no interchange" << endl;
			}
			else {
				for (const auto& bus : stop_and_bus.second) {
					if (bus != r.bus) {
						os << " " << bus;
					}
				}
				os << endl;
			}
		}
	}
  return (os);
}

struct AllBusesResponse {
	map<string,vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.empty()) {
			os << "No buses" << endl;
		}
	else {
		for (const auto& bus_with_stops : r.buses_to_stops) {
			os << "Bus " << bus_with_stops.first << ":";
			for(const auto& stop : bus_with_stops.second){
				os << " " << stop;
			}
			os << endl;
		}
	}
  return (os);
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
	  buses_to_stops.insert(make_pair(bus, stops));
      for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
	  if (stops_to_buses.count(stop) == 0) {
		  return (BusesForStopResponse{vector<string>()});
	  }
	  else {
		  return (BusesForStopResponse{stops_to_buses.at(stop)});
	  }
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
	  vector<pair<string, vector<string>>> stops_for_bus;
	  if (buses_to_stops.count(bus) > 0) {
		  for (const auto& stop : buses_to_stops.at(bus)) {
			  stops_for_bus.push_back(make_pair(stop, stops_to_buses.at(stop)));
		  }
	  }
	  return (StopsForBusResponse{bus, stops_for_bus});
  }

  AllBusesResponse GetAllBuses() const {
	  return (AllBusesResponse{buses_to_stops});
  }
private:
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return (0);
}
