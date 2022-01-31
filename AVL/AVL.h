#include <iostream>
using namespace std;

class Node
{
public:
    Node *lChild;
    Node *rChild;
    int data;
    int height;
    Node(int data)
    {
        this->data = data;
        height = 1;
        lChild = NULL;
        rChild = NULL;
    }
};

int getHeight(Node *root)
{
    int lHeight = (root && root->lChild) ? root->lChild->height : 0;
    int rHeight = (root && root->rChild) ? root->rChild->height : 0;
    return max(lHeight, rHeight) + 1;
}

int getBalanceFactor(Node *root)
{
    int lHeight = (root && root->lChild) ? root->lChild->height : 0;
    int rHeight = (root && root->rChild) ? root->rChild->height : 0;
    return lHeight - rHeight;
}

Node *LLRotation(Node *root)
{
    Node *lRoot = root->lChild;
    Node *rlRoot = root->lChild->rChild;
    lRoot->rChild = root;
    root->lChild = rlRoot;
    root->height = getHeight(root);
    lRoot->height = getHeight(lRoot);
    return lRoot;
}

Node *LRRotation(Node *root)
{
    Node *lRoot = root->lChild;
    Node *rlRoot = lRoot->rChild;
    lRoot->rChild = rlRoot->lChild;
    root->lChild = rlRoot->rChild;
    rlRoot->rChild = root;
    rlRoot->lChild = lRoot;
    lRoot->height = getHeight(lRoot);
    root->height = getHeight(root);
    rlRoot->height = getHeight(rlRoot);
    return rlRoot;
}

Node *RLRotation(Node *root)
{
    Node *rRoot = root->rChild;
    Node *lrRoot = rRoot->lChild;
    root->rChild = lrRoot->lChild;
    rRoot->lChild = lrRoot->rChild;
    lrRoot->lChild = root;
    lrRoot->rChild = rRoot;
    root->height = getHeight(root);
    rRoot->height = getHeight(rRoot);
    lrRoot->height = getHeight(lrRoot);
    return lrRoot;
}

Node *RRRotation(Node *root)
{
    Node *rRoot = root->rChild;
    root->rChild = rRoot->lChild;
    rRoot->lChild = root;
    root->height = getHeight(root);
    rRoot->height = getHeight(rRoot);
    return rRoot;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        Node *child = new Node(data);
        return child;
    }
    if (data <= root->data)
    {
        root->lChild = insertNode(root->lChild, data);
    }
    else
    {
        root->rChild = insertNode(root->rChild, data);
    }
    root->height = getHeight(root);
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor == 2)
    {
        if (getBalanceFactor(root->lChild) == 1)
        {
            root = LLRotation(root);
        }
        else
        {
            root = LRRotation(root);
        }
    }
    else if (balanceFactor == -2)
    {
        if (getBalanceFactor(root->rChild) == 1)
        {
            root = RLRotation(root);
        }
        else
        {
            root = RRRotation(root);
        }
    }
    return root;
}