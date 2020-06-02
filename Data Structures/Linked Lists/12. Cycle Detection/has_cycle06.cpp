bool hasCycleRecursive(SinglyLinkedListNode* head, unordered_set<SinglyLinkedListNode*> seen) {
    if ( head == NULL ) return false;
    if ( seen.count(head) ) return true;
    seen.insert(head);
    return hasCycleRecursive(head->next, seen);
}

bool has_cycle(SinglyLinkedListNode* head) {
    return hasCycleRecursive(head,unordered_set<SinglyLinkedListNode*>());
}