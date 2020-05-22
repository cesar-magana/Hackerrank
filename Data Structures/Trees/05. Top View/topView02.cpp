void leftView(Node* node) {
    if( node ) {
        leftView( node->left );
        cout << node->data << " ";
    }
}
void rightView(Node* node) {
    if ( node ) {
        cout << node->data << " ";
        rightView( node->right );
    }
}

void topView(Node * root) {
    leftView(root);
    rightView(root->right);
}

