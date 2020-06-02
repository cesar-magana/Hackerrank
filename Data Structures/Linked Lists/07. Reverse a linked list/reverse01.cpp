SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if ( !head || !head->next ) return head;
    SinglyLinkedListNode* temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
