void inOrder(Node *root) {
    if( !root )
        return;

    stack<Node*> stk;
    Node* current = root;

    while( !stk.empty() || current ){
        if( current ) {
            stk.push( current );
            current = current->left;
        }
        else {
            Node* node = stk.top();
            stk.pop();
            cout << node->data << " ";
            current = node->right;
        }
    }
}