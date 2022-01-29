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
int height(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

class Pair
{
public:
    int height;
    int diameter;
    Pair()
    {
        height = 0;
        diameter = 0;
    }
};

template <class T>
Pair diameter(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        Pair nullResult;
        return nullResult;
    }
    Pair leftSubTree = diameter<T>(root->left);
    Pair rightSubTree = diameter<T>(root->right);
    Pair currentTree;
    currentTree.height = max(leftSubTree.height, rightSubTree.height) + 1;
    currentTree.diameter = max(leftSubTree.diameter, max(rightSubTree.diameter, rightSubTree.height + leftSubTree.height));
    return currentTree;
}

int main(void)
{
    Pair result;
    BinaryTreeNode<int> *root = takeInputLevelWise<int>();
    cout << diameter<int>(root).diameter << endl;
    return 0;
}