//................ Inorder Traversal.........
// Algorithm Inorder(tree)
// 1. Traverse the left subtree, i.e., call Inorder(left->subtree)
// 2. Visit the root.
// 3. Traverse the right subtree, i.e., call Inorder(right->subtree)

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printInorder(struct Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	return 0;
}

// OUTPUT : Inorder traversal of binary tree is 
// 4 2 5 1 3 
