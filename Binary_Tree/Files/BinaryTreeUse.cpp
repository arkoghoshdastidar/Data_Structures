#include "BinaryTreeNode.h"

int main(void)
{
    BinaryTreeNode<int> *root = takeInputLevelWise<int>();
    cout << diameter<int>(root) << endl;
    return 0;
}