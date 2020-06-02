int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* node = head;
    for (int i = 0; i < positionFromTail+1; i++) {
        head = head->next;
    }
    while ( head ) {
        head = head->next;
        node = node->next;
    }
    return node->data;    
}