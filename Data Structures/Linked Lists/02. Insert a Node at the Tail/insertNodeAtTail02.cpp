SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if ( head == NULL ) {
        return node;
    }
    SinglyLinkedListNode* ret = head;
    while ( head->next ) {
        head = head->next;
    }
    head->next = node;
    return ret;
}