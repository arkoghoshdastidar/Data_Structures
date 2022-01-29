//bubble sort iterative
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

Node *bubbleSort(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *tempH1 = head;
    Node *tempH2 = NULL;
    while(tempH1->next)
    {
        tempH2 = tempH1->next;
        while(tempH2)
        {
            if(tempH2->data < tempH1->data)
            {
                int tempData = tempH1->data;
                tempH1->data = tempH2->data;
                tempH2->data = tempData;
            }
            tempH2 = tempH2->next;
        }
        tempH1 = tempH1->next;
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}