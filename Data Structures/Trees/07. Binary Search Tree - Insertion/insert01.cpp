Node * insert(Node * root, int value) {
    if ( !root ) {
        root = new Node(value);
    }
    if ( value < root->data) {
        root->left = insert( root->left, value );
    }
    else if ( value > root->data ) {
        root->right = insert( root->right, value );
    }
    else {
        root->data = value;
    }
    return root;            
}