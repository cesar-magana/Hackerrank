int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* checker = head1;
    while( checker ) {
        SinglyLinkedListNode* pointer = head2;
        while( pointer ) {
            if( pointer == checker ) {
                return pointer->data;
            }
            pointer = pointer->next;
        }
        checker = checker->next;
    }
    return 0;
}