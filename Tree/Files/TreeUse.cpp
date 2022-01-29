#include "TreeNode.h"

int main(void)
{
    TreeNode<int> *root = InputTreeLevelWise<int>();
    printLevelWise<int>(root);
    cout << maxDataNode<int>(root)->data << endl;
    printKLevel(root, 3);
    return 0;
}