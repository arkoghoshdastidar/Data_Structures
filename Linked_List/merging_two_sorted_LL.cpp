// Code: Merge Two Sorted LL
// Send Feedback
// You have been given two sorted(in ascending order) singly linked lists of integers.
// Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
// Note :
// Try solving this in O(1) auxiliary space.

// No need to print the list, it has already been taken care.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.

// The second line of the input contains the elements of the second sorted singly linked list separated by a single space.
// Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
// Output :
// For each test case/query, print the resulting sorted singly linked list, separated by a single space.

// Output for every test case will be printed in a seperate line.

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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (!head1)
    {
        return head2;
    }
    else if (!head2)
    {
        return head1;
    }
    else if (!head1 && !head2)
    {
        return NULL;
    }

    Node *fHead = NULL;
    Node *fTail = NULL;

    if (head1->data < head2->data)
    {
        fHead = head1;
        fTail = head1;
        head1 = head1->next;
    }
    else
    {
        fHead = head2;
        fTail = head2;
        head2 = head2->next;
    }

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            fTail->next = head1;
            fTail = head1;
            head1 = head1->next;
        }
        else
        {
            fTail->next = head2;
            fTail = head2;
            head2 = head2->next;
        }
    }

    if (!head1)
    {
        fTail->next = head2;
    }

    else if (!head2)
    {
        fTail->next = head1;
    }
    return fHead;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}