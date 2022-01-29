#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
class Pair
{
public:
    bool status;
    int smallest;
    int largest;
    Pair()
    {
        smallest = -1;
        largest = -1;
        status = true;
    }
};

Pair IsBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair nullResult;
        return nullResult;
    }

    Pair result;
    result.smallest = root->data;
    result.largest = root->data;
    result.status = true;

    if (root->left == NULL && root->right == NULL)
    {
        return result;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        Pair rightChild = IsBST(root->right);
        result.status = ((root->data <= root->right->data) && rightChild.status);
        if (rightChild.smallest < root->data)
            result.status = false;
        result.smallest = min(root->data, rightChild.smallest);
        result.largest = max(root->data, rightChild.largest);
        return result;
    }
    else if (root->left != NULL && root->right == NULL)
    {
        Pair leftChild = IsBST(root->left);
        result.status = ((root->data > root->left->data) && leftChild.status);
        if (root->data <= leftChild.largest)
            result.status = false;
        result.smallest = min(root->data, leftChild.smallest);
        result.largest = max(root->data, leftChild.largest);
        return result;
    }
    Pair rightChild = IsBST(root->right);
    Pair leftChild = IsBST(root->left);
    result.status = ((root->data > root->left->data) && (root->data <= root->right->data) && (rightChild.status) && (leftChild.status));
    if (root->data <= leftChild.largest || root->data > rightChild.smallest)
        result.status = false;
    result.smallest = min(root->data, min(leftChild.smallest, rightChild.smallest));
    result.largest = max(root->data, max(leftChild.largest, rightChild.largest));
    return result;
}

bool isBST(BinaryTreeNode<int> *root)
{
    return IsBST(root).status;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}