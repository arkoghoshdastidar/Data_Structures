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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;
#include <vector>
void getpath(BinaryTreeNode<int> *root, int data, vector<int> *path)
{
    if(root == NULL)
        return;
    if(root->data == data)
    {
        path->push_back(root->data);
        return;
    }

    path->push_back(root->data);
    getpath(root->left, data, path);
    if(path->back() == data)
        return;
    
    getpath(root->right, data, path);
    if(path->back() == data)
        return;
    else
        path->pop_back();
    return;
}

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    vector<int>* path = new vector<int>();
    getpath(root, data, path);
    if(path->size() == 0)
        return NULL;
    else 
        return path;
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
    int t;
    cin >> t;
    while(t--)
    {
        BinaryTreeNode<int> *root = takeInput();
        int k;
        cin >> k;
        vector<int> *output = getPath(root, k);

        if (output != NULL)
        {
            for (int i = 0; i < output->size(); i++)
            {
                cout << output->at(i) << " ";
            }
        }
        delete root;
    }
}