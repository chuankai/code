#include <iostream>
#include "tree.hpp"

using namespace std;
int main() {
	cout << "\t#### Tree test ####\n";

	unordered_map<int, int> tree_def = {
		{0, 50},
		{1, 30},
		{2, 80},
		{4, 40},
		{5, 60},
		{11, 55}
	};


	KLIB::Tree tree {tree_def};
	tree.printTree();

	return 0;
}
