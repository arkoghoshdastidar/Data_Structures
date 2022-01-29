// Code : Find sum of nodes
// Send Feedback
// Given a generic tree, find and return the sum of all nodes present in the given tree.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.   
// Output Format :
// The first and only line of output prints the sum of all nodes of the given generic tree.
// Constraints:
// Time Limit: 1 sec
// Sample Input 1:
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1:
// 190

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

int sumOfNodes(TreeNode<int>* root)
{
    if(root == NULL)
        return 0;
    int ans = 0;
    for(int i=0; i<root->children.size(); i++)
        ans += sumOfNodes(root->children[i]);
    return ans + root->data;
}