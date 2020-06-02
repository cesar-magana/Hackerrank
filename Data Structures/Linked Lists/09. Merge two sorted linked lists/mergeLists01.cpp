SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
    if ( !l1 ) return l2;
    if ( !l2 ) return l1;
    
    if ( l1->data < l2->data ) {
        l1->next = mergeLists( l1->next, l2 );
        return l1;
    }
    else {
        l2->next = mergeLists( l2->next, l1 );
        return l2;
    }
}