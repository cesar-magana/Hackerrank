
void levelOrder(Node * root) {
    queue<Node*> que;
    que.push(root); 

    while ( !que.empty() ) {
        Node* current = que.front();
        que.pop();
        cout << current->data << " "; 
        if ( current-> left)
            que.push( current->left );
        if ( current->right ) 
            que.push( current->right );
    }
}

