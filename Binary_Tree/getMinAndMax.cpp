// Min and Max of Binary Tree
// Send Feedback
// For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
// Return the output as an object of Pair class, which is already created.
// Note:
// All the node data will be unique and hence there will always exist a minimum and maximum node data.
// Input Format:
// The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
// Output Format:
// The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.
// Constraints:
// 2 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec
// Sample Input 1:
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// Sample Output 1:
// 1 14
// Sample Input 2:
// 10 20 60 -1 -1 3 50 -1 -1 -1 -1
// Sample Output 2:
// 3 60

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
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    pair<int, int> result(root->data, root->data);
    if (root->left == NULL && root->right == NULL)
    {
        return result;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        pair<int, int> right = getMinAndMax(root->right);
        result.first = min(root->data, right.first);
        result.second = max(root->data, right.second);
    }
    else if (root->left != NULL && root->right == NULL)
    {
        pair<int, int> left = getMinAndMax(root->left);
        result.second = max(root->data, left.second);
        result.first = min(root->data, left.first);
    }
    else
    {
        pair<int, int> right = getMinAndMax(root->right);
        pair<int, int> left = getMinAndMax(root->left);
        result.first = min(root->data, min(right.first, left.first));
        result.second = max(root->data, max(right.second, left.second));
    }
    return result;
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
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}