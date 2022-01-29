#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(node *head)
{
    node *tempHead = head;
    while (tempHead)
    {
        if(tempHead->next == NULL){
            cout << tempHead->data << " | " << tempHead->next << endl;
            break;
        }
        else{
            cout << tempHead->data << " | " << tempHead->next << " -> ";
            tempHead = tempHead->next;
        }
    }
}

node* takeInput(void){
    node* head = NULL;
    node* tempPtr = NULL;
    int data, condition = 1;
    do
    {
        cin >> data;
        node* tempNode = new node(data);
        if(head == NULL){
            head = tempNode;
            tempPtr = head;
        }
        else{
            tempPtr->next = tempNode;
            tempPtr = tempNode;
        }
        cout << "Press 1 to continue entering nodes in the linked list else press 0.";
        cin >> condition;
    } while (condition == 1);
    return head;   
}

node* insertNode(node* head, int data, int i){
    node* tempNode = new node(data);
    node* tempPtr = head;
    int count = 0;
    if(i == 0){
        tempNode -> next = head;
        head = tempNode;
        return head;
    }
    while(tempPtr != NULL && count < i-1){
        count++;
        tempPtr = tempPtr -> next;
    }
    if(tempPtr != NULL){
        tempNode -> next = tempPtr -> next;
        tempPtr -> next = tempNode;
    }
    return head;
}