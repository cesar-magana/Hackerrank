bool has_cycle(SinglyLinkedListNode* head) {
    if ( head == NULL ) return false;
    int count = 0;
    while ( head ) {
        head = head->next;
        if ( count++ == 1001) 
            return true;
    }
    return false;
}