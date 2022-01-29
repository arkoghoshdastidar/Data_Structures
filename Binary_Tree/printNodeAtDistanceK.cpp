// Print nodes at distance k from node
// Send Feedback
// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
// Example:
// For a given input tree(refer to the image below):
// 1. Target Node: 5
// 2. K = 2
// alt txt

// Starting from the target node 5, the nodes at distance K are 7 4 and 1.
// Input Format:
// The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

// The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
// Output Format:
// All the node data at distance K from the target node will be printed on a new line.

// The order in which the data is printed doesn't matter.
// Constraints:
// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec
// Sample Input 1:
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 3 1
// Sample Output 1:
// 9
// 6
// Sample Input 2:
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 3 3
// Sample Output 2:
// 4
// 5

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
void printNode(BinaryTreeNode<int> *root, int K)
{
    if (root == NULL)
        return;
    if (K == 0)
    {
        cout << root->data << endl;
        return;
    }
    else if (K > 0)
    {
        printNode(root->left, K - 1);
        printNode(root->right, K - 1);
    }
}

pair<bool, int> nodeAtDistanceK(BinaryTreeNode<int> *root, int node, int K)
{
    if (root == NULL)
    {
        pair<bool, int> retVal;
        retVal.first = false;
        retVal.second = K;
        return retVal;
    }
    else if (root->data == node)
    {
        printNode(root, K);
        pair<bool, int> retVal;
        retVal.first = true;
        retVal.second = K - 1;
        return retVal;
    }
    pair<bool, int> left = nodeAtDistanceK(root->left, node, K);
    if (left.first == true)
    {
        pair<bool, int> retVal;
        if (left.second == 0)
        {
            cout << root->data << endl;
            retVal.first = false;
            return retVal;
        }
        else
        {
            printNode(root->right, left.second - 1);
            retVal.first = true;
            retVal.second = left.second - 1;
            return retVal;
        }
    }
    pair<bool, int> right = nodeAtDistanceK(root->right, node, K);
    if (right.first == true)
    {
        pair<bool, int> retVal;
        if (right.second == 0)
        {
            cout << root->data << endl;
            retVal.first == false;
            return retVal;
        }
        else
        {
            printNode(root->left, right.second - 1);
            retVal.first = true;
            retVal.second = right.second - 1;
            return retVal;
        }
    }
    return right;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int K)
{
    nodeAtDistanceK(root, node, K);
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}