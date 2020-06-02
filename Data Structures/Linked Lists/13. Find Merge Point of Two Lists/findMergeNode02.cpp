int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    unordered_set<SinglyLinkedListNode*> visited;
    while ( true ) {
        if ( head1 ) {
            head1 = head1->next;
            if ( visited.count( head1 ) ) {
                return head1->data;
            }
            visited.insert( head1 );
        }
        if ( head2 ) {
            head2 = head2->next;
            if ( visited.count( head2 ) ) {
                return head2->data;
            }
            visited.insert( head2 );
        }
    }
}