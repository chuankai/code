#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string a = "hello";
	string& b = a;

	cout << b << '\n';

	return 0;
}
