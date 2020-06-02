bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* fast = head;
    
    while( fast && fast->next ) {
        fast = fast->next->next;
        head = head->next;
        if( head == fast )
            return true;
    }
    return false;
}