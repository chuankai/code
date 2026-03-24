#include <memory>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	vector<int> a {1, 2, 3};
	vector<int> b {10, 20, 30};

	a.append_range(b);

	for (int i: a)
		cout << i << " - ";

	cout << '\n';
	
	return 0;
}
