SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if ( head == NULL ) {
        head = new SinglyLinkedListNode(data);
        return head;
    }
    SinglyLinkedListNode* ret = head;
    while ( head->next ) {
        head = head->next;
    } 
    head->next = new SinglyLinkedListNode( data );
    return ret;
}