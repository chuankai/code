#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class StringCompare {
private:
	unordered_map<char, int> val;

public:
	StringCompare (string& order) {
		for (size_t i = 0; i < order.size(); ++i)
			val[order[i]] = i;
	}
	
	int cmp(string& a, string& b) {
		size_t len = min(a.size(), b.size());
		for (size_t i = 0; i < len; ++i) {
			int d = val[a[i]] - val[b[i]];
			if (d != 0)
				return d;
		}

		return a.size() - b.size();
	}
};

bool isAlienSorted(vector<string>& words, string order) {
	StringCompare sc(order);

	for (size_t i = 0; i < words.size() - 1; ++i) {
		string& a = words[i];
		string& b = words[i + 1];

		if (sc.cmp(a, b) > 0)
			return false;
	}

	return true;
}

int main() {
	vector<string> words {"apple","app"};
	string order {"abcdefghijklmnopqrstuvwxyz"};
	
	cout << "It's " << (isAlienSorted(words, order) ? "" : "not ") << "sorted\n";

	return 0;
}
