# Tasks from week 3 of course

## C++ Yellow belt
This repository contains my solutions to tasks from week 3 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)
### Program decomposition - 2

In the task "Program decomposition" [https://www.coursera.org/learn/c-plus-plus-yellow/programming/k6Xm2/diekompozitsiia-proghrammy] we split the monolithic code into a set of functions and classes. Now we will take one more step and split our program into several files. In this task, you need to create a project consisting of the following files:

1.query.h, we put in it:

- enum class QueryType
- struct Query
- istream & operator >> (istream & is, Query & q) declaration

2.query.cpp, put in it

- definition of istream & operator >> (istream & is, Query & q);

3. responses.h:

- struct BusesForStopResponse
- ostream & operator << (ostream & os, const BusesForStopResponse & r)
- struct StopsForBusResponse
- ostream & operator << (ostream & os, const StopsForBusResponse & r)
- struct AllBusesResponse
- ostream & operator << (ostream & os, const AllBusesResponse & r)

4. responses.cpp: definitions for everything declared in responses.h

5.bus_manager.h: Declaring the BusManager class

6.bus_manager.cpp: method definitions of the BusManager class

7.main.cpp: function main

**How to submit a project for review**

For programming assignments, Coursera allows you to submit only one file for review, so in order to submit your project to the testing system, you need to pack all your files into an archive and send it for review. Supported archive formats: rar, zip, 7z, tar, tar.gz, and many others (for unpacking we use the dtrx program, on the page with its description there is a complete list of supported formats).
How your solution will be tested

Below you are given a stub for the main.cpp file, which contains the main function. This is exactly the same stub that was given in the "Program Decomposition" task. Testing your solution will be done in two stages. At the first stage, the automated testing system will unpack the archive you sent and collect the extracted files into an executable file. In this case, the main function in your project will be replaced with the one given in the template of the main.cpp file. This executable will then be run against the test suite. Testing is performed in the same way as for most tasks in our course: the test is fed to stdin, the program execution time is measured, and then stdout is analyzed.

The second stage will test individual files in your project. It is checked that the query.h file actually contains the enumerated type QueryType, that BusManager :: GetBusesForStop returns a well-formed BusesForStopResponse object, etc.

[Template_main.cpp](./Template_main.cpp) file.
