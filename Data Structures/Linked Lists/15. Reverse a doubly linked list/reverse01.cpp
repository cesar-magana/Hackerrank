DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if ( head == NULL || head->next == NULL )
        return head;
    DoublyLinkedListNode* current = head;
    DoublyLinkedListNode* previous = NULL;
    DoublyLinkedListNode* next = NULL;

    while ( current ) {
        next = current->next;
        current->next = previous;
        current->prev = next;
        previous = current;
        current = next;
    }
    return previous;
}