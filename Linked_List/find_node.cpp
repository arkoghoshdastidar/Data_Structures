// Find a Node in Linked List
// Send Feedback
// You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.
// Note :
// Assume that the Indexing for the singly linked list always starts from 0.
// Input format :
// The first line contains an Integer 'T' which denotes the number of test cases.

// The first line of each test case or query contains the elements of the singly linked list separated by a single space.

// The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.
// Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence -1 would never be a list element.
// Output format :
// For each test case, return the index/position of 'N' in the singly linked list. Return -1, otherwise.

// Output for every test case will be printed in a separate line.
// Note:
// You do not need to print anything; it has already been taken care of. Just implement the given function.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int findNode(Node *head, int n)
{
    int count = 0;
    Node *tempPtr = head;
    while (tempPtr)
    {
        if (tempPtr->data == n)
        {
            return count;
        }
        count++;
        tempPtr = tempPtr->next;
    }
    return -1;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNode(head, val) << endl;
    }
}