SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    if ( position == 0 ) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode( data );
        node->next = head;
        return node;
    }
    else {
        head->next = insertNodeAtPosition( head->next, data, position-1 );
        return head;
    }
}