DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if ( head == NULL || head->next == NULL )
        return head;
    DoublyLinkedListNode* temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}