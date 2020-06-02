SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if ( head == NULL ) {
        return new SinglyLinkedListNode(data);
    }
    else {
        head->next = insertNodeAtTail(head->next,data);
    }
    return head;
}