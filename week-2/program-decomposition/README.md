# Tasks from week 2 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 1 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Program decomposition

### Introduction

In the course "White Belt on C ++" we had the task "Bus stops - 1" [https://www.coursera.org/learn/c-plus-plus-white/programming/Gi9dw/avtobusnyie-ostanovki-1]. In this task, you will be given the correct solution, contained entirely inside the main function. You will need to decompose this solution into predetermined blocks so that the resulting program will also correctly solve the problem. The condition of the problem "Bus stops - 1" is given below.
How will your program be tested

The automatic checking system will replace the main function in your program with the one given to you in the starter.cpp file, compile the resulting file and run it on tests for the "Bus stops - 1" task.

### Condition of the problem "Bus stops - 1"
Implement a bus route storage system. You need to handle the following requests:

- NEW_BUS bus stop_count stop1 stop2 ... - add a bus route named bus and stop_count stops named stop1, stop2, ...
- BUSES_FOR_STOP stop - display the names of all bus routes passing through the stop stop.
- STOPS_FOR_BUS bus - display the names of all stops on the bus route with a list of buses that you can change to at each of the stops.
- ALL_BUSES - display a list of all routes with stops.

### Input format

The first line of input contains the number of queries Q, then Q lines are followed by descriptions of the queries.

It is guaranteed that all names of routes and stops consist only of Latin letters, numbers and underscores.

For each NEW_BUS bus request stop_count stop1 stop2 ... it is guaranteed that there is no bus route, the number of stops is greater than 0, and after the stop_count number exactly the same number of stop names follows, and all names in each list are different.
Output format

For each request, except NEW_BUS, print the corresponding answer to it:

- On the BUSES_FOR_STOP stop query, print a space-separated list of buses passing through this stop, in the order in which they were created by the NEW_BUS commands. If stop stop does not exist, print No stop.
- On the STOPS_FOR_BUS bus query, print the descriptions of bus stops on separate lines in the order in which they were specified in the corresponding NEW_BUS command. The description of each stop stop must be of the form Stop stop: bus1 bus2 ..., where bus1 bus2 ... is the list of buses passing through the stop stop, in the order in which they were created by the NEW_BUS commands, except for the original bus route. If no bus passes through the stop stop, except for the bus, print no interchange instead of the list of buses for it. --- If the bus route does not exist, print No bus.
- For ALL_BUSES, print the descriptions of all buses in alphabetical order. The description of each bus route must be of the form Bus bus: stop1 stop2 ..., where stop1 stop2 ... is the list of bus stops in the order in which they were specified in the corresponding NEW_BUS command.
- If there are no buses, output No buses.

Warning

The problem statement above contains many important details. If you are not sure that you have not missed a single one, re-read the condition again.
