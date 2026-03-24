#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;


vector<int> exclusiveTime(int n, vector<string>& logs) {
	enum class State {
		start,
		end
	};

	struct function_log {
		int id;
		State st; 
		int timestamp;
	};

	vector<int> times(n, 0);
	vector<unique_ptr<function_log>> funclogs;

	for (string log : logs) {
		size_t start = 0;
		size_t pos;

		vector<string> vals;
		while ((pos = log.find_first_of(':', start)) != string::npos) {
			vals.push_back(log.substr(start, pos - start));
			start = pos + 1;
		}
		
		vals.push_back(log.substr(start, log.size() - start));

		State s;
		if (vals[1] == "start") {
			s = State::start;
		} else if (vals[1] == "end") {
			s = State::end;
		} else {
			cout << "Unknown state: " << vals[1] << '\n';
		}

		funclogs.push_back(make_unique<function_log>(stoi(vals[0]), s, stoi(vals[2])));
	}

	for (auto& l : funclogs)
		cout << '{' << l->id << ", " << (l->st == State::start ? "start" : "end") << ", " << l->timestamp << "}\n";


	if (funclogs[0]->st != State::start) {
		cout << "Incorrect state\n";
		return times;
	} 

	stack<int> callstack {};
	int begin;
	
	for (auto log = funclogs.begin(); log < funclogs.end(); ++log) {
		function_log* pf = log->get();

		if (pf->st == State::end) {
			times[callstack.top()] += pf->timestamp - begin + 1;
			begin = pf->timestamp + 1;
			callstack.pop();
		} else if (pf->st == State::start) {
			if (!callstack.empty()) {
				times[callstack.top()] += pf->timestamp - begin;
			}
			begin = pf->timestamp;
			callstack.push(pf->id);
		} 
	}

	return times;
}

int main() {
	vector<string> logs {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"};
	auto times = exclusiveTime(3, logs);
	
	for (size_t i = 0; i < times.size(); ++i)
		cout << i << " : " << times[i] << '\n';

	return 0;
}
