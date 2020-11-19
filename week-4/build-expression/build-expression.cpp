#include <string>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct Operation {
	char action;
	int	number;
};

bool RequireBrackets(char previous, char current) {
	if ( (previous == '-' || previous == '+') && (current == '*' || current == '/') ) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int x; //initial number
	int n; //number of operations
	string operation; //operation

	cin >> x;
	cin >> n;
	vector<Operation> operations(n);
	for (int i = 0; i < n; ++i) {
		cin >> operations[i].action;

		cin >> operations[i].number;
	}

	deque<string> expression;
	expression.push_back(to_string(x));
	char previous = '*';
	for (auto operation : operations) {
		if (RequireBrackets(previous, operation.action)) {
			expression.push_front("(");
			expression.push_back(")");
		}
		expression.push_back(" ");
		expression.push_back(string(1, operation.action));
	    expression.push_back(" ");
	    expression.push_back(to_string(operation.number));
	    previous = operation.action;
	}
	for (auto s : expression) {
		cout << s;
	}
return 0;
}
