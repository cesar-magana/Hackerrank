DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    if ( head == NULL ) {
        return newNode;
    }
    else if ( head->data >= data ) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    } else {
        head->next = sortedInsert(head->next, data);
        head->next->prev = head;
    }
    return head;
}