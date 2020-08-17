/*
 * bus_manager.h
 *
 *  Created on: Apr 17, 2020
 *      Author: tlegenkamidollayev
 */

#ifndef BUS_MANAGER_H_
#define BUS_MANAGER_H_
#include <vector>
#include <string>
#include <map>
#include "responses.h"

using namespace std;

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;
private:
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;
};




#endif /* BUS_MANAGER_H_ */
