#include <vector>
#include <iostream>
#include <stack>
#include <utility>
#include <string>
#include <cassert>

using namespace std;

pair<int, int> getOperands(stack<int>& operands) {
	assert(operands.size() >= 2);
	int a;
	int b;
	a = operands.top();
	operands.pop();
	b = operands.top();
	operands.pop();

	return make_pair(a, b);
}

int evalRPN(vector<string>& tokens) {
	stack<int> operands;

	for (const string& token: tokens) {
		if (token == "+") {
			auto ops = getOperands(operands);
			operands.push(ops.second + ops.first);
		} else if (token == "-") {
			auto ops = getOperands(operands);
			operands.push(ops.second - ops.first);
		} else if (token == "*") {
			auto ops = getOperands(operands);
			operands.push(ops.second * ops.first);
		} else if (token == "/") {
			auto ops = getOperands(operands);
			operands.push(ops.second / ops.first);
		} else {
			operands.push(stoi(token));
		}	
	}

	return operands.top();
}

int main() {
	vector<vector<string>> test_tokens {
		{"2", "1", "+", "3", "*"},
		{"4", "13", "5", "/", "+"},
		{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
	};

	for (auto test: test_tokens) {
		cout << evalRPN(test) << '\n';
	}

	return 0;
}

