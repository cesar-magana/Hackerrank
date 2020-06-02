int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int i = 0;
    SinglyLinkedListNode* result = head;
    SinglyLinkedListNode* curr = head;
    while ( curr ) {
        curr = curr->next;
        if ( i++ > positionFromTail ) {
            result = result->next;
        }
    }
    return result->data;   
}