SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = NULL;
    unordered_set<int> set;
    while ( current ) {
        if ( set.count(current->data) ) {
            previous->next = current->next;
        }
        else {
            set.insert(current->data);
            previous = current;
        }
        current = current->next;
    }
    return head;
}