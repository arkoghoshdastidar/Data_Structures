// Swap two Nodes of LL
// Send Feedback
// You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
// Note :
// Remember, the nodes themselves must be swapped and not the datas.

// No need to print the list, it has already been taken care. Only return the new head to the list.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the singly linked list separated by a single space.

// The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
//  Remember/consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
// Output format :
// For each test case/query, print the elements of the updated singly linked list.

// Output for every test case will be printed in a seperate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.
// 0 <= i < M
// 0 <= j < M

// Time Limit: 1sec
// Sample Input 1 :
// 1
// 3 4 5 2 6 1 9 -1
// 3 4

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

Node *swapNodes(Node *head, int i, int j)
{
    if(!head)
        return head;
    if(i == j)
        return head;
    
    int count = 0;
    Node *temphead = head;
    Node *tempptr = NULL;
    Node *previ = NULL;
    Node *curri = head;
    Node *currj = head;
    Node *prevj = NULL;
    
    while(temphead)
    {
    	if(count == i)
            break;
        else
        {
            previ = curri;
            curri = curri->next;
            count++;
        }
    }
    
    temphead = head;
    count = 0;
    
    while(temphead)
    {
        if(count == j)
            break;
        else
        {
            prevj = currj;
            currj = currj->next;
            count++;
        }
    }
    
    if(previ == NULL)
    {
        if(curri->next == currj)
        {
            tempptr = currj->next;
            head = currj;
            currj->next = curri;
            curri->next = tempptr;
        }
        else
        { 
        	tempptr = currj->next;
        	currj->next = head->next;
        	prevj->next = curri;
        	curri->next = tempptr;
        	head = currj;
        }
    }
    else
    {
        if(curri->next == currj)
        {
            tempptr = currj->next;
            currj->next = curri;
            curri->next = tempptr;
            previ->next = currj;
        }
        else
        {
            tempptr = currj->next;
        	currj->next = curri->next;
        	prevj->next = curri;
        	curri->next = tempptr;
        	previ->next = currj;
        }
    }
    return head;
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}