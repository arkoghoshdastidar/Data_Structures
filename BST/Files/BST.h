// Code: BST Class
// Send Feedback
// Implement the BST class which includes following functions -
// 1. search
// Given an element, find if that is present in BST or not. Return true or false.
// 2. insert -
// Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
// 3. delete -
// Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
// 4. printTree (recursive) -
// Print the BST in ithe following format -
// For printing a node with data N, you need to follow the exact format -
// N:L:x,R:y
// where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
// There is no space in between.
// You need to print all nodes in the recursive format in different lines.


class BST {
	BinaryTreeNode<int> *root;
    
    bool search(int data, BinaryTreeNode<int> *root){
        if(root == NULL){
            return false;
        }else if(data == root->data){
            return true;
        }
        else if(data < root->data){
            return search(data, root->left);
        }else{
            return search(data, root->right);
        }
    }
    
    void print(BinaryTreeNode<int> *root){
        if(root == NULL)
            return;
        
        cout << root->data << ":";
        if(root->left != NULL)
            cout << "L:" << root->left->data << ",";
        if(root->right != NULL)
            cout << "R:" << root->right->data;
        cout << endl;
        
        print(root->left);
        print(root->right);
    }
    
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int> *root){
        if(root == NULL){
            BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
            return root;
        }
        if(data <= root->data){
            root->left = insert(data, root->left);
        }else{
            root->right = insert(data, root->right);
        }
        return root;
    }
    
    pair<int, BinaryTreeNode<int>*> minimum(BinaryTreeNode<int>* root){
       pair<int, BinaryTreeNode<int>*> result;
        result.first = root->data;
        result.second = root->right;
        if(root->left != NULL){
            pair<int, BinaryTreeNode<int>*> left = minimum(root->left);
            root->left = left.second;
            result.first = left.first;
        }else{
            delete root;
        }
        return result;
    }
    
    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int> *root){
        if(root == NULL)
            return NULL;
        if(root->data == data){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left == NULL && root->right != NULL){
                BinaryTreeNode<int> *right = root->right;
                delete root;
                return right;
            }else if(root->left != NULL && root->right == NULL){
                BinaryTreeNode<int> *left = root->left;
                delete root;
                return left;
            }else{
                pair<int ,BinaryTreeNode<int>*> right = minimum(root->right);
                root->right = right.second;
                root->data = right.first;
            }
        }else if(data <= root->data){
            root->left = remove(data, root->left);
        }else{
            root->right = remove(data, root->right);
        }
        return root;
    }
    
   public:
    BST() { 
        root = NULL;
    }
    void remove(int data) { 
        root = remove(data, root);
    }

    void print() { 
    	return print(root);    
    }

    void insert(int data) { 
        root = insert(data, root);
    }

    bool search(int data) {
        return search(data, root);
    }
};