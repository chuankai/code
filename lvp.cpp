#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <stack>

using namespace std;

bool validateRange(int begin, int end, vector<vector<bool>>& rangeValidity, const string& ps) {
	if (ps[begin] == '(' && ps[end] == ')') {
		if (end - begin == 1 || rangeValidity[begin + 1][end - 1]) {
			rangeValidity[begin][end] = true;
			return true;
		}
	}

	for (int i = begin + 2; i < end; i += 2) {
		if (rangeValidity[begin][i - 1] && rangeValidity[i][end]) {
			rangeValidity[begin][end] = true;
			break;
		}
	}

	return rangeValidity[begin][end];
}

int longestValidParentheses(const string& ps) {
	int len = ps.size();
	vector<vector<bool>> rangeValidity(len, vector<bool>(len, false));
	int max_len = 0;

	for (int i = 2; i <= len; i += 2) {
		for (int j = 0; j + i <= len; ++j) {
			bool valid = validateRange(j, j + i - 1, rangeValidity, ps);
			if (valid && i > max_len)
				max_len = i;
		}
	}

	return max_len;
}

int lvp(const string& ps) {
	int max_len = 0;
	stack<int> left_brackets {};

	for (size_t i = 0; i < ps.size(); ++i) {
		char c = ps[i];
		if (c == '(') {
			if (left_brackets.empty())
				left_brackets.push(i - 1);

			left_brackets.push(i);
		} else if (c == ')') {
 			if (left_brackets.size() > 1) {
				left_brackets.pop();
				max_len = max(max_len, static_cast<int>(i - left_brackets.top())); 
			} else if (left_brackets.size() == 1) {
				left_brackets.pop();
			}
		}
	}

	return max_len;
}

/*
 *  )(()())
 */
int main() {
	vector<string> pss {
		"(()))(()())()",
		"(()",
		")()())",
		"",
		"()(()",
	};

	for (string ps: pss) {
		cout << longestValidParentheses(ps) << '\n';
		cout << lvp(ps) << '\n';
	}
	
	return 0;
}

