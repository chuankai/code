#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
	unordered_map<int, int> count;
	++count[7];

	cout << count[7] << '\n';

	if (count[7] == 1)
		cout << "true\n";
	
	return 0;
}
