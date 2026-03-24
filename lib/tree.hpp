#include <unordered_map>
#include <functional>

#ifndef __TREE_HPP__
#define __TREE_HPP__

namespace KLIB
{

#include "treenode.hpp"

class Tree {
private:
	TreeNode* root = nullptr;

public:
	Tree(std::unordered_map<int, int>& def) {
		std::function<void(TreeNode*, int)> createTree = [&](TreeNode* root, int idx){
			int left_idx = idx * 2 + 1;
			int right_idx = left_idx + 1;
			if (def.contains(left_idx)) {
				root->left = new TreeNode(def[left_idx]);
				createTree(root->left, left_idx);
			}

			if (def.contains(right_idx)) {
				root->right = new TreeNode(def[right_idx]);
				createTree(root->right, right_idx);
			}
		};

		if (!def.contains(0))
			return;

		root = new TreeNode(def[0]);
		createTree(root, 0);
	}

	~Tree() {
		auto free_node = [](this auto&& self, TreeNode* node) {
			if (node == nullptr)
				return;

			self(node->left);
			self(node->right);
			delete node;
		};

		free_node(root);
	}

	void printTree() {
		std::function<void(TreeNode*)> _printTree = [&](TreeNode* node) {
			if (node == nullptr)
				return;

			if (node->left != nullptr)
				std::cout << '(' << node->left->val << ") <- ";

			std::cout << '(' << node->val << ')';

			if (node->right != nullptr)
				std::cout << " -> (" << node->right->val << ')';

			std::cout << '\n';

			_printTree(node->left);
			_printTree(node->right);
		};

		_printTree(root);
	}

	TreeNode* getRoot() {
		return root;
	}
};

} // namespace KL

#endif // __TREE_HPP__
