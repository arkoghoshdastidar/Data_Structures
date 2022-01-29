// Code : PostOrder Traversal
// Send Feedback
// Given a generic tree, print the post-order traversal of given tree.
// The post-order traversal is: visit child nodes first and then root node.
// Input format:
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
// Output Format :
// The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.
// Constraints:
// Time Limit: 1 sec
// Sample Input 1:
// 10 3 20 30 40 2 400 50 0 0 0 0 
// Sample Output 1:
// 400 50 20 30 40 10

#include <vector>
using namespace std;

template <class T>
class TreeNode
{
    public:
    int data;
    vector <TreeNode<T> *> children;
    TreeNode(){ this->data = 0;}
    TreeNode(int data){ this->data = data;}
};

template <class T>
void printPostOrder(TreeNode<T> *root)
{
    if(root == NULL)
    {
        return;
    }
    for(int i=0; i<root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}

/*
    PRE-ORDER-PRINTING
*/

template <class T>
void printPreOrder(TreeNode<T> *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for(int i=0; i<root->children.size(); i++)
    {
        printPreOrder(root->children[i]);
    }
}