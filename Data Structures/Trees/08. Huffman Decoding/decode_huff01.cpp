void decode_huff(node * root, string s) {
    node* node = root;
    for(char c : s ) {
        if( c == '0' ) 
            node = node->left;
        else 
            node = node->right;
        if( node->data != '\0' ) {
            cout << node->data;
            node = root;
        }
    }    
}
