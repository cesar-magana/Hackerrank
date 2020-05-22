void postOrder(Node *root) {
    stack<Node*> stk;
    Node* current = root;  

    while( true ) {  
        if( current ) {  
            if( current->right )   
                stk.push( current->right );  
            stk.push( current );  
            current = current->left;  
            continue;  
        }  
        if( stk.empty( ) )   
            return;  
        current = stk.top();
        stk.pop();  

        if( current->right && ! stk.empty() && current->right == stk.top() ) {  
            stk.top();
            stk.pop();
            stk.push( current );  
            current = current->right;  
        } else {  
            cout << current->data << " ";  
            current = NULL;  
        }  
    }
}
