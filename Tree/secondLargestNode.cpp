// Second Largest Element In Tree
// Send Feedback
// Given a generic tree, find and return the node with second largest value in given tree.
// Note: Return NULL if no node with required value is present.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
// Output Format :
// The first and only line of output contains data of the node with second largest data.
// Constraints:
// Time Limit: 1 sec
// Sample Input 1 :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1 :
// 40

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

class Pair
{
public:
    TreeNode<int> *largestNode;
    TreeNode<int> *secondLargestNode;
    Pair()
    {
        largestNode = NULL;
        secondLargestNode = NULL;
    }
};

Pair getSecondLargest(TreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair p;
        return p;
    }

    Pair result;
    result.largestNode = root;
    result.secondLargestNode = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        Pair tempAns = getSecondLargest(root->children[i]);
        if (result.largestNode->data == result.secondLargestNode->data)
        {
            if (tempAns.largestNode->data > result.largestNode->data)
            {
                result.largestNode = tempAns.largestNode;
                if (tempAns.largestNode->data != tempAns.secondLargestNode->data && tempAns.secondLargestNode->data > result.secondLargestNode->data)
                    result.secondLargestNode = tempAns.secondLargestNode;
            }
            else if (tempAns.largestNode->data < result.largestNode->data)
            {
                result.secondLargestNode = tempAns.largestNode;
            }
            else
            {
                if (tempAns.largestNode->data != tempAns.secondLargestNode->data)
                    result.secondLargestNode = tempAns.secondLargestNode;
            }
        }
        else
        {
            if (result.largestNode->data > tempAns.largestNode->data)
            {
                if (result.secondLargestNode->data < tempAns.largestNode->data)
                {
                    result.secondLargestNode = tempAns.largestNode;
                }
            }
            else if (result.largestNode->data < tempAns.largestNode->data)
            {
                result.secondLargestNode = result.largestNode;
                result.largestNode = tempAns.largestNode;
                if (tempAns.largestNode->data != tempAns.secondLargestNode->data && tempAns.secondLargestNode->data > result.secondLargestNode->data)
                    result.secondLargestNode = tempAns.secondLargestNode;
            }
            else
            {
                if (tempAns.largestNode->data != tempAns.secondLargestNode->data && tempAns.secondLargestNode->data > result.secondLargestNode->data)
                    result.secondLargestNode = tempAns.secondLargestNode;
            }
        }
    }

    return result;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    Pair result = getSecondLargest(root);
    if (result.largestNode == NULL || result.largestNode->data == result.secondLargestNode->data)
        return NULL;
    return result.secondLargestNode;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}