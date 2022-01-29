// AppendLastNToFirst
// Send Feedback
// You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

// The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.
// Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
// Output format :
// For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

// Output for every test case will be printed in a seperate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// 0 <= N < M
// Time Limit: 1sec

// Where 'M' is the size of the singly linked list.
// Sample Input 1 :
// 2
// 1 2 3 4 5 -1
// 3
// 10 20 30 40 50 60 -1
// 5
// Sample Output 1 :
// 3 4 5 1 2
// 20 30 40 50 60 10

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

int length(Node* head){
    if(head == NULL)
        return 0;
    int size = length(head->next);
    return size+1;
}

Node *appendLastNToFirst(Node *head, int n){
    if(head == NULL)
        return head;
    
    int count = 1;
    int size = length(head);
    Node *tempPtr = head;
    
    if(size - n <= 0 || n == 0)
        return head;
    
    while(count < size - n){
        count++;
        tempPtr = tempPtr -> next;
    }
    
    Node* newHead = tempPtr -> next;
    Node* oldHead = head;
    tempPtr -> next = NULL;
    tempPtr = newHead;
    
    while(tempPtr->next != NULL){
        tempPtr = tempPtr -> next;
    }
    tempPtr -> next = oldHead;
    
    return newHead;
}

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}