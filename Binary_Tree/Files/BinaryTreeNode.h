#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

template <class T>
BinaryTreeNode<T> *takeInput()
{
    int nodeData;
    cout << "Enter node data : ";
    cin >> nodeData;
    cout << endl;
    if (nodeData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(nodeData);
    BinaryTreeNode<T> *leftChild = takeInput<T>();
    BinaryTreeNode<T> *rightChild = takeInput<T>();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

template <class T>
void printTree(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

template <class T>
BinaryTreeNode<T> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter the root data : ";
    cin >> rootData;
    cout << endl;

    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);
    queue<BinaryTreeNode<T> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<T> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout << "Enter the left child data of " << front->data << " : ";
        cin >> leftChildData;
        cout << endl;

        if (leftChildData != -1)
        {
            BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(leftChildData);
            front->left = temp;
            pendingNodes.push(temp);
        }

        int rightChildData;
        cout << "Enter the right child data of " << front->data << " : ";
        cin >> rightChildData;
        cout << endl;

        if (rightChildData != -1)
        {
            BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(rightChildData);
            front->right = temp;
            pendingNodes.push(temp);
        }
    }
    return root;
}

template <class T>
int countNodes(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 1;
    count += countNodes(root->left);
    count += countNodes(root->right);
    return count;
}

template <class T>
void printPreOrder(BinaryTreeNode<T> *root) // root->left->right
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

template <class T>
void printPostOrder(BinaryTreeNode<T> *root) // left->right->root
{
    if (root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

template <class T>
void printInorder(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

template <class T>
int height(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

template <class T>
int diameter(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int currentNodeDiameter = height<T>(root->left) + height<T>(root->right);
    int leftTreeDiameter = diameter<T>(root->left);
    int rightTreeDiameter = diameter<T>(root->right);
    return max(currentNodeDiameter, max(leftTreeDiameter, rightTreeDiameter));
}