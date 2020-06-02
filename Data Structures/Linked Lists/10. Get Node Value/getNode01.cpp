int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    stack<int> stk;
    
    SinglyLinkedListNode* current = head;
    while ( head ) {
        stk.push( head->data );
        head = head->next;
    }
    for ( int i = 0; i < positionFromTail; i++ ) {
        stk.pop();
    }
    return stk.top();
}