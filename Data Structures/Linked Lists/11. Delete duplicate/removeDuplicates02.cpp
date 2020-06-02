SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while ( current ) {
        SinglyLinkedListNode* runner = current;
        while ( runner->next ) {
            if (runner->next->data == current->data) {
                runner->next = runner->next->next;
            }
            else {
                runner = runner->next;
            }
        }
       current = current->next;
    }
    return head;
}