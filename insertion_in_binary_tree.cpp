// .........................Insertion in a Binary Tree.........................

// Problem: Given a Binary Tree and a Key. The task is to insert the key into the binary tree at first position available in level order.

#include <iostream> 
#include <queue> 
using namespace std; 

struct Node { 
    int key; 
    struct Node* left, *right; 
}; 

struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 

void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 

    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 

void insert(struct Node* temp, int key) 
{ 
    queue<struct Node*> q; 
    q.push(temp); 

    while (!q.empty()) { 
        struct Node* temp = q.front(); 
        q.pop(); 

        if (!temp->left) { 
            temp->left = newNode(key); 
            break; 
        } else
            q.push(temp->left); 

        if (!temp->right) { 
            temp->right = newNode(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 

int main() 
{   
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 

    cout << "Inorder traversal before insertion:"; 
    inorder(root); 

    int key = 12; 
    insert(root, key); 

    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 

    return 0; 
}


// Output

// Inorder traversal before insertion: 7 11 10 15 9 8 
// Inorder traversal after insertion: 7 11 12 10 15 9 8 
