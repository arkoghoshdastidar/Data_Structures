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

class Pair
{
    public:
        Node* const head;
        Node* tail;
        Pair();
        Pair(Node *head,Node *tail) : head(head), tail(tail){
        }
};

Pair reverseLLBetter(Node *H)
{
    if(H->next == NULL || H == NULL)
    {
        Pair ans(H,H);
        return ans;
    }

    Pair smallAns = reverseLLBetter(H->next);
    smallAns.tail->next = H;
    H->next = NULL;
    smallAns.tail = H;
    return smallAns;
}

Node *reverseLinkedListRec(Node* head)
{
    return reverseLLBetter(head).head;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}