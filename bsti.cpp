#include <iostream>
#include <stack>
#include "tree.hpp"


using namespace std;

class BSTIterator {
private:
	stack<KLIB::TreeNode*> _breadcrumbs;
	KLIB::TreeNode* _dummy;

public:
	BSTIterator(KLIB::TreeNode* root) {
		_dummy = new KLIB::TreeNode {-1, nullptr, root};
		_breadcrumbs.push(_dummy);
	}

	~BSTIterator() {
		delete _dummy;
	}

	int next() {
		if (!hasNext())
			return -1;

		KLIB::TreeNode* node = _breadcrumbs.top();
		_breadcrumbs.pop();

		if (node->right) {
			_breadcrumbs.push(node->right);
			while (_breadcrumbs.top()->left)
				_breadcrumbs.push(_breadcrumbs.top()->left);
		}

		return _breadcrumbs.top()->val;
	}

	bool hasNext() {
		return _breadcrumbs.size() > 1 || _breadcrumbs.top()->right != nullptr;
	}
};

int main() {
	cout << "\t#### BSTI test ####\n";

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

	BSTIterator bi(tree.getRoot());
	while (bi.hasNext())
		cout << bi.next() << '\n';

	return 0;
}
