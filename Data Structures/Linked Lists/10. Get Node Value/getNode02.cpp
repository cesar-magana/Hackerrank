int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* current = head;
    int count = 0;
    while ( head ) {
        count++;
        head = head->next;
    }
    for ( int i = 0; i < count-positionFromTail-1; i++ ) {
        current = current->next;
    }
    return current->data;
}