SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if( !head )
        return head;
    stack<SinglyLinkedListNode*> stk; 
    SinglyLinkedListNode* cursor = head; 
    while( cursor ){
        stk.push( cursor );
        head = cursor; 
        cursor = cursor->next;
    }
    while( !stk.empty() ){
        cursor = stk.top();
        stk.pop();
        if ( stk.empty() )
            cursor->next = NULL; 
        else 
            cursor->next = stk.top();
    }
    return head;
}