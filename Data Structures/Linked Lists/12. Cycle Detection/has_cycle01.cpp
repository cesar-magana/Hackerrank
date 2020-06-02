bool has_cycle(SinglyLinkedListNode* head) {
    if ( head == NULL ) return false;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head->next;

    while ( fast && fast->next ) {
        if ( slow == fast ) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}