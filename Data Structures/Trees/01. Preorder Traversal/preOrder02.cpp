void preOrder(Node *root) {
    if ( !root )
        return;
    stack <Node*> stk;
    stk.push( root );
    while ( stk.empty() == false ) {
        Node* node = stk.top();
        stk.pop();
        cout << node->data << " ";
        if ( node->right )
            stk.push( node->right );
        if ( node->left )
            stk.push( node->left );
    }
}