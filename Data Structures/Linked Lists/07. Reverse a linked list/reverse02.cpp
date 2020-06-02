SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if ( !head || !head->next ) 
        return NULL;
    
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = NULL;
    SinglyLinkedListNode* next = NULL;
    
    while ( current ) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}