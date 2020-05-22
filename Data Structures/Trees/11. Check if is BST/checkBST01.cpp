#include <climits>
bool checkBST(Node* root, int min, int max) {
    if ( !root ) 
        return true;
    if ( root->data < min || root->data > max )
        return false;
    return checkBST( root->left, min, root->data-1 ) && checkBST( root->right, root->data+1, max );
}

bool checkBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}