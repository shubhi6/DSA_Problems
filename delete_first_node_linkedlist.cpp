// Given a linked list, the task is to remove the first node of the linked list and update the head pointer of the linked list. 

// Examples: 

// Input : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// Output : 2 -> 3 -> 4 -> 5 -> NULL

// Input : 2 -> 4 -> 6 -> 8 -> 33 -> 67 -> NULL
// Output : 4 -> 6 -> 8 -> 33 -> 67 -> NULL

// To remove the first node, we need to make the second node as head and delete the memory allocated for the first node.  

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node *deleteFirstNode(node *head)
{
    if(head == NULL) {
        cout << "List is empty. No node to delete.\n";
        return NULL;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printList(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head=NULL;
    head = deleteFirstNode(head); // Deleting the first node (if exists)
    
    head=new node(20);
    head->next=new node(30);
    head->next->next=new node(40);

    printList(head);

    return 0;
}

