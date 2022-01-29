#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    friend class ada;
};

class ada
{
    node* head;
    node* tail;
    int size;
    public:
    ada()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void back(void)
    {
        if(!size)
        {
            cout << "No job for Ada?" << endl;
        }
        else if(size == 1)
        {
            cout << tail->data << endl;
            size = size - 1;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout << tail->data << endl;
            size = size - 1;
            node* temptail = tail;
            tail = tail->prev;
            delete temptail;
            tail->next = NULL;
        }
    }

    void front()
    {
        if(!size)
        {
            cout << "No job for Ada?" << endl;
        }
        else if(size == 1)
        {
            cout << head->data << endl;
            size = size - 1;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout << head->data << endl;
            node* temphead = head;
            head = head->next;
            size = size - 1;
            delete temphead;
            head->prev = NULL;
        }
    }

    void reverse()
    {
        if(!head)
        {
            return;
        }
        node* previous = NULL;
        node* current = head;
        node* nxt = head->next;

        while(nxt)
        {
            current->next = previous;
            current->prev = nxt;
            previous = current;
            current = nxt;
            nxt = nxt->next; 
        }
        current->next = previous;
        current->prev = nxt;
        tail = head;
        head = current;
    }

    void print()
    {
        node* temp = head;
        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push_back(int N)
    {
        node* tempnode = new node(N);
        if(!size)
        {
            head = tempnode;
            tail = tempnode;
        }
        else
        {
            tail->next = tempnode;
            tempnode->prev = tail;
            tail = tail->next;
        }
        size = size + 1;
    }

    void toFront(int N)
    {
        node* tempnode = new node(N);
        if(!size)
        {
            head = tempnode;
            tail = tempnode;
        }
        else
        {
            head->prev = tempnode;
            tempnode->next = head;
            head = head->prev;
        }
        size = size + 1;
    }
};

int main(void)
{
    int t;
    cin >> t;
    ada main_ada_object;
    int value;
    string query;
    while(t--)
    {
        cin >> query;
        if(query == "back")
        {
            main_ada_object.back();
        }
        else if(query == "front")
        {
            main_ada_object.front();
        }
        else if(query == "reverse")
        {
            main_ada_object.reverse();
        }
        else if(query == "toFront")
        {
            cin >> value;
            main_ada_object.toFront(value);
        }
        else if(query == "push_back")
        {
            cin >> value;
            main_ada_object.push_back(value);
        }
    }
    return 0;
}