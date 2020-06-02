bool has_cycle(SinglyLinkedListNode* head) {
    if ( head == NULL ) return false;
    unordered_set<SinglyLinkedListNode*> set;
    set.insert(head);
    while ( head->next ) {
        if ( set.count(head->next) )
            return true;
        else
            set.insert( head->next );
        head = head->next;
    }
    return false;
}