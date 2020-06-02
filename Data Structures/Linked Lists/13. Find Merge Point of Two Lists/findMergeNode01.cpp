int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    unordered_set<SinglyLinkedListNode*> set;
    while ( head1 ) {
        set.insert( head1 );
        head1 = head1->next;
    }
    while ( head2 ) {
        if ( set.count( head2 ) )
            break;
        head2 = head2->next;
    }
    return head2->data;
}