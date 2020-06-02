SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if ( position == 0 ) {
        return head->next;
    }
    SinglyLinkedListNode* current = head;
    for ( int i = 1; i < position; i++ ) {
        current = current->next;
    }
    current->next = current->next->next;
    return head;
}