#ifndef RESPONSES_H_
#define RESPONSES_H_
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

struct BusesForStopResponse {
	vector<string> buses; //vector to hold buses for specified stop
};

//output operator to print all buses for specified stop
ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	string bus;
	vector<pair<string, vector<string>>> stops_for_bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	map<string,vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);




#endif /* RESPONSES_H_ */
