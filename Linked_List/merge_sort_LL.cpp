// Code: Merge Sort
// Send Feedback
//  Given a singly linked list of integers, sort it using 'Merge Sort.'
// Note :
// No need to print the list, it has already been taken care. Only return the new head to the list.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
// Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
// Output format :
// For each test case/query, print the elements of the sorted singly linked list.

// Output for every test case will be printed in a seperate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.

// Time Limit: 1sec

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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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

Node* midPoint(Node* head)
{
    if(!head)
        return head;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* head1, Node* head2)
{
    if(!head1 && !head2)
        return head1;
    else if(!head1)
        return head2;
    else if(!head2)
        return head1;
    
    Node* fHead = NULL;
    Node* fTail = NULL;
    
    if(head1->data < head2->data)
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
    
    while(head1 && head2)
    {
        if(head1->data < head2->data)
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
    
    if(!head1)
        fTail->next = head2;
    else if(!head2)
        fTail->next = head1;
    
    return fHead;    
}

Node *mergeSort(Node *head)
{
	  if(head == NULL || head->next == NULL)
          return head;
    
    Node* tempPtr = NULL;
    Node* tempHead = NULL;
    
    tempPtr = midPoint(head);
    tempHead = tempPtr->next;
    tempPtr->next = NULL;
    
    head = mergeSort(head);
    tempHead = mergeSort(tempHead);
    
    return merge(head, tempHead);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}