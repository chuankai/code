#include <iostream>
#include <stack>
#include<unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class FreqStack {
private:
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> freq_stack;
	int max_freq = 0;

public:
	FreqStack() {
	}

	void push(int val) {
		++freq[val];		
		freq_stack[freq[val]].push(val);
		max_freq = max(max_freq, freq[val]);
	}

	int pop() {
		if (max_freq == 0)
			return -1;

		int ret = freq_stack[max_freq].top();
		--freq[ret];
		freq_stack[max_freq].pop();
		if (freq_stack[max_freq].empty())
			--max_freq;

		return ret;
	}
};


int main() {
	enum action {
		PUSH,
		POP,
	};

	struct op {
		action act;
		int val;
	};


	array<struct op, 7> ops = { {
		{PUSH, 5},
		{PUSH, 7},
		{PUSH, 5},
		{PUSH, 7},
		{PUSH, 4},
		{PUSH, 5},
		{POP, 5}
	} };

	FreqStack fs;

	for (auto& op: ops) {
		if (op.act == PUSH) {
			fs.push(op.val);
			cout << "push: " << op.val << '\n';
		} else {
			assert(fs.pop() == op.val);
			cout << "pop: " << op.val << '\n';
		}
	}

	return 0;
}
