//Find Kth Smallest in BST

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	int lCount;
	Node(int x)
	{
		data = x;
		left = right = NULL;
		lCount = 0;
	}
};

Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);

	if (x < root->data) {
		root->left = insert(root->left, x);
		root->lCount++;
	}
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

Node* kthSmallest(Node* root, int k)
{
	if (root == NULL)
		return NULL;
	int count = root->lCount + 1;
	if (count == k)
		return root;
	if (count > k)
		return kthSmallest(root->left, k);
	return kthSmallest(root->right, k - count);
}
int main()
{
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
    int size = sizeof(keys) / sizeof(keys[0]); 
    for (int i = 0; i < size; ++i)
        root = insert(root, keys[i]);
    int k = 4;
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;
    return 0;
}

// Output
// K-th Smallest Element is 12
