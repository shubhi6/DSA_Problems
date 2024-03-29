// ........................................Height of Binary Tree......................................

// Given a binary tree, the task is to find the height of the tree.
// Height of the tree is the number of edges in the tree from the root to the deepest node, Height of the empty tree is 0.

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

int maxDepth(node* node) {
	if (node == NULL)
		return 0;
	else {
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

node* newNode(int data) {
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main() {
	node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height of tree is " << maxDepth(root);
	return 0;
}

// Output
// Height of tree is 3
