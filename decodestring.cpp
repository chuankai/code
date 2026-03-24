#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <stack>

using namespace std;

string decodeString(string s) {
	stack<pair<int, string>> groups {};
	string repeat_str {};
	int curr_repeat_num = 1; 
	string curr_str {};

	for (char c : s) {
		if (isalpha(c)) { 
			curr_str += c;
		} else if (isdigit(c)) {
			repeat_str += c;	
		} else if (c == '[') {
			groups.push({curr_repeat_num, curr_str});
			curr_repeat_num = stoi(repeat_str);
			repeat_str.clear();
			curr_str.clear();
		} else if (c == ']') {
			string tmp_str = curr_str;
			for (int i = 0; i < curr_repeat_num - 1; ++i)
				curr_str += tmp_str; 

			auto parent_group = groups.top();
			groups.pop();
			curr_str = parent_group.second + curr_str;
			curr_repeat_num = parent_group.first;
		}
	}

	return curr_str;
}

int main() {
	string es {"2[abc]3[cd]ef"};

	cout << decodeString(es) << '\n';

	return 0;
}
