#ifndef __TREENODE_H__
#define __TREENODE_H__

struct TreeNode {
	int val = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode() = default;
	TreeNode(int x) : val {x} {}
	TreeNode(int x, TreeNode* leftChild, TreeNode* rightChild) : val {x}, left {leftChild}, right {rightChild} {}
};

#endif // __TREENODE_H__
