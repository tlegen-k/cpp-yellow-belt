## Introduction

In the C ++ White Belt course, the final task was to develop a database that worked with pairs (date, event). In this task, you need to develop this database by teaching it to select and delete events that meet a given condition, as well as dividing its code into several files.

In more detail, your program should be able to handle a set of commands:

- Add date event - add a pair (date, event) to the database;
- Print - display the entire contents of the database;
- Find condition - display all records contained in the database that meet the condition condition;
- Del condition - delete from the database all records that meet the condition condition;
- Last date - display a record with the last event that happened no later than this date.

Conditions in Find and Del commands impose certain restrictions on dates and events, for example:

- Find date <2017-11-06 - find all events that happened before November 6, 2017;
- Del event! = "Holiday" - remove all events from the database, except for "holiday";
- Find date> = 2017-01-01 AND date <2017-07-01 AND event == "sport event" - find all "sport event" events that occurred in the first half of 2017;
- Del date <2017-01-01 AND (event == "holiday" OR event == "sport event") - remove from the database all "holiday" and "sport event" events that occurred before 2017.

In commands of both types, conditions can be empty: all events fall under such a condition.

## Program structure

Below you are given blanks for files

- condition_parser.h / cpp - in the video lecture “The task of parsing an arithmetic expression. Description of the solution ”we have demonstrated the construction of an abstract syntax tree for arithmetic expressions. The implementation of this algorithm for parsing conditions in Find and Del commands is contained in the ParseCondition function, declared and fully implemented in the condition_parser.h / cpp files;

- token.h / cpp - contain a ready-made tokenizer, which is used in the ParseCondition function;
- main.cpp - contains a ready-made function main.

You need to analyze the issued code and develop the missing classes and functions:

- the Database class, which is a database - you have to create its public interface yourself, based on how it is used in the main function;
- classes Node, EmptyNode, DateComparisonNode, EventComparisonNode and LogicalOperationNode - to form their hierarchy and public interface, analysis of the main and ParseCondition functions will help you;
- the Date class, and the ParseDate function and the stream operator for the Date class.

For verification, you must send an archive consisting of files:

- date.h / cpp - these files must contain declarations and definitions of the Date class, the ParseDate function and the stream operator for the Date class;
- database.h / cpp - these files must contain the declaration and definition of the Database class;
- node.h / cpp - these files should contain declarations and definitions of the Node class, as well as all its descendants (see above), which are nodes of the abstract syntax tree formed by the ParseCondition function;
- condition_parser.h / cpp;
- token.h / cpp;
- main.cpp;
- other .h and .cpp files that you see fit to create in your solution.

## How your solution will be tested

Testing your solution will be done in two stages. At the first stage, the automated testing system will unpack the archive you sent and collect the extracted files into an executable file. This executable will then be run against the test suite. Testing is performed in the same way as for most tasks in our course - the test is fed to stdin, the program execution time is measured, and then stdout is analyzed.

The second stage will test individual files in your project. It is checked that the file date.h does indeed contain a declaration of the Date class, that Database :: FindIf correctly searches the passed predicate, etc. We expect your classes to have an interface that is captured in the main function. Therefore, in the Database and Node classes, make the signatures of the methods that are used in the main function.

## Input and output format

The standard input contains commands for working with the database, one command per line. Your program should read them and print the results to standard output. The command processing rules are shown below.

### Add command

Upon encountering the Add date event command, your program should add the (date, event) pair to the database and then display it when searching (Find command) or printing (Print command). It is not necessary to save identical events that occurred on the same day: adding an existing pair (date, event) to the database should be ignored. Many different events can occur on the same date, the database must be able to save them all.

It is guaranteed that the date field in the Add command has the format "Year-Month-Day", where Year is an integer from 0 to 9999, Month is a month number from 1 to 12 inclusive, Day is a day number from 1 to 31 inclusive ... The date must be followed by a space separating it from the event Examples of valid dates: 2017-11-07, 0-2-31.

The rest of the line in the Add command defines the event. It can contain spaces, so it is convenient to use the getline function to read it. It is guaranteed that the event name cannot contain the quotation mark ("). Thus, this character can only be found in the condition in the Find and Del commands, being a delimiter of the event name.

### Example

For the Add 2017-11-07 big sport event command, the program should add a pair (2017-11-07, big sport event) to the database.
### Del command

Upon encountering the Del condition command, your program should delete all events that meet the condition condition from the database and print the number of deleted N entries to standard output in the format "Removed N entries". If the condition is empty, the command should result in a cleanup of the entire database.

### Print Command

Upon encountering the Print command, your program should display all pairs (date, event) that are currently contained in the database. Pairs must be printed one per line. They must be sorted by date in ascending order. Events within the same date must be displayed in the order they were added (except for those already deleted and attempts to add repeats).

Dates should be displayed in the format YYYY-MM-DD, where G, M, D are the numbers of the numbers of the year, month and day, respectively. If a number has fewer digits than necessary, it must be padded with zeros, for example: 0001-01-01 - January 1 of the first year.

### Find command

Having met the Find condition command, your program should display all pairs (date, event) that are currently contained in the database and satisfy the condition condition. The output format is similar to the Print command. An empty search is equivalent to the Print command. At the end, the command should output the line Found N entries, where N is the number of pairs found.

### Last Command

On the Last date command, you need to display the last of the events that happened to date. More formally:

- among all the available dates of events, you need to find the largest one, not exceeding date;
- from all events with such a date, select the last added one and display it in a format similar to that of the Print command;
- if date is less than all available dates, output "No entries".
