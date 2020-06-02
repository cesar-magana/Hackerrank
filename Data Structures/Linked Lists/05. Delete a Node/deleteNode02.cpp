SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if ( position == 0 ) {
        return head->next;
    }
    else {
        head->next = deleteNode( head->next, position-1 );
    }
    return head;
}