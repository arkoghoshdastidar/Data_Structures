#include "AVL.h"
#define COUNT 10

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->rChild, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print2DUtil(root->lChild, space);
}

int main(void)
{
    Node *root = new Node(50);
    root = insertNode(root, 40);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 60);
    root = insertNode(root, 70);
    root = insertNode(root, 80);
    root = insertNode(root, 90);
    root = insertNode(root, 100);
    root = insertNode(root, 85);
    root = insertNode(root, 35);
    print2DUtil(root, 0);
    return 0;
}