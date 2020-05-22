void topView(Node * root) {
    stack<int> stk;
    stk.push( root->data );
    Node* current = root;
    while ( root->left ) {
        stk.push( root->left->data );
        root = root->left;
    }
    while ( !stk.empty() ) {
        cout << stk.top() << " ";
        stk.pop();
    }
    while ( current->right ) {
        cout << current->right->data << " ";
        current = current->right;
    }
}
