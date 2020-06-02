int getLength(SinglyLinkedListNode* head) {
    if ( head == NULL ) return 0;
    return 1 + getLength(head->next);
}
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int length = getLength(head);
    for (int i = 0; i < length - positionFromTail - 1; i++) {
        head = head->next;
    }
    return head->data;
}