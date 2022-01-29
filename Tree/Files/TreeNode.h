#include <vector>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode()
    {
        data = 0;
    }
    TreeNode(int data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for(int i=0; i<children.size(); i++)
            delete children[i];
    }
};

template <class T>
TreeNode<T>* maxDataNode(TreeNode<T>* root) {
    if(root == NULL)
        return root;
    TreeNode<T> *maxNode = root;
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<T> *smallAns = maxDataNode(root->children[i]);
        if(smallAns->data > maxNode->data)
            maxNode = smallAns;
    }
    return maxNode;
}

template <class T>
TreeNode<T> *InputTree(void)
{
    T data;
    cout << "Enter node data : ";
    cin >> data;
    cout << endl;
    TreeNode<T> *root = new TreeNode<T>(data);

    int number_of_children;
    cout << "Enter number of child nodes of " << data << " : ";
    cin >> number_of_children;
    cout << endl;

    while (number_of_children--)
    {
        root->children.push_back(InputTree<T>());
    }
    return root;
}

template <class T>
void print_tree(TreeNode<T> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " : ";

    for (int i = 0; i < root->children.size(); i++)
    {
        if (i == root->children.size() - 1)
            cout << root->children.at(i)->data;
        else
            cout << root->children.at(i)->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print_tree<T>(root->children[i]);
    }
}

template <class T>
TreeNode<T> *InputTreeLevelWise()
{
    T data;
    cout << "Enter the data of the root node." << endl;
    cin >> data;
    TreeNode<T> *root = new TreeNode<T>(data);
    queue<TreeNode<T> *> parentNodes;
    parentNodes.push(root);

    while (!parentNodes.empty())
    {
        TreeNode<T> *frontNode = parentNodes.front();
        parentNodes.pop();
        int children;
        cout << "Enter the number of children of " << frontNode->data << endl;
        cin >> children;

        for (int i = 0; i < children; i++)
        {
            cout << "Enter the data of the " << (i + 1) << " child node of " << frontNode->data << endl;
            cin >> data;
            TreeNode<T> *tempNode = new TreeNode<T>(data);
            frontNode->children.push_back(tempNode);
            parentNodes.push(tempNode);
        }
    }
    return root;
}

template <class T>
void printLevelWise(TreeNode<T> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<T> *> remainingNodes;
    remainingNodes.push(root);

    while (!remainingNodes.empty())
    {
        TreeNode<T> *frontNode = remainingNodes.front();
        remainingNodes.pop();
        cout << frontNode->data << ":";
        for (int i = 0; i < frontNode->children.size(); i++)
        {
            remainingNodes.push(frontNode->children[i]);
            if (i == frontNode->children.size() - 1)
            {
                cout << frontNode->children[i]->data;
                break;
            }
            cout << frontNode->children[i]->data << ",";
        }
        cout << endl;
    }
}

template <class T>
int NumberOfNodes(TreeNode<T> *root)
{
    if(root == NULL)
        return 0;
    int count = 0;

    for(int i=0; i<root->children.size(); i++)
        count += NumberOfNodes(root->children[i]);
    return count + 1;
}

template <class T>
void printKLevel(TreeNode<T> *root, int k)
{
    if(root == NULL)
    {
        return;
    }    
    if(k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for(int i=0; i<root->children.size(); i++)
    {
       printKLevel(root->children[i], k-1);
    }
}