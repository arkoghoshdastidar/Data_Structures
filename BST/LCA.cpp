// LCA of BST
// Send Feedback
// Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
// LCA
// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.
// Example:
// In this example, the green coloured node is the LCA to A and B.
// Alt Text

// Note:
// It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
// Example:
// Alt Text

// Note:
// 1. If out of 2 nodes only one node is present, return that node.
// 2. If both are not present, return -1.
// Input format:
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
// The following line of input contains two integers, denoting the value of data of two nodes of given BST.
// Output Format:
// The first and only line of output contains the data associated with the lowest common ancestor node.
// Constraints:
// Time Limit: 1 second
// Sample Input 1:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 2 10
// Sample Output 1:
// 8
// Sample Input 2:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 2 6
// Sample Output 2:
// 5
// Sample Input 3:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 12 78
// Sample Output 3:
// -1

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
class Pair
{
public:
    int val1;
    int val2;
    int lca;
    Pair()
    {
        val1 = -1;
        val2 = -1;
        lca = -1;
    }
};

Pair getLCA2(BinaryTreeNode<int> *root, int val1, int val2)
{
    if (root == NULL)
    {
        Pair result;
        return result;
    }
    Pair current;

    if (root->data <= min(val1, val2))
    {
        // search right subtree
        Pair right = getLCA2(root->right, val1, val2);
        if (right.lca != -1)
        {
            current = right;
        }
        else
        {
            if (root->data == min(val1, val2))
            {
                current.val1 = root->data;
                if (right.val2 == max(val1, val2))
                {
                    current.val2 = max(val1, val2);
                    current.lca = root->data;
                }
            }
            else
            {
                current = right;
            }
        }
    }
    else if (root->data >= max(val1, val2))
    {
        // search left subtree
        Pair left = getLCA2(root->left, val1, val2);
        if (left.lca != -1)
        {
            current = left;
        }
        else
        {
            if (root->data == max(val1, val2))
            {
                current.val2 = max(val1, val2);
                if (left.val1 == min(val1, val2))
                {
                    current.val1 = min(val1, val2);
                    current.lca = root->data;
                }
            }
            else
            {
                current = left;
            }
        }
    }
    else
    {
        // search whole tree
        Pair right = getLCA2(root->right, val1, val2);
        Pair left = getLCA2(root->left, val1, val2);
        current.val1 = left.val1;
        current.val2 = right.val2;
        if (current.val1 != -1 && current.val2 != -1)
            current.lca = root->data;
    }
    return current;
}

int getLCA(BinaryTreeNode<int> *root, int val1, int val2)
{
    Pair result = getLCA2(root, val1, val2);
    if (result.lca != -1)
        return result.lca;
    else
    {
        if (result.val1 != -1)
            return result.val1;
        return result.val2;
    }
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}