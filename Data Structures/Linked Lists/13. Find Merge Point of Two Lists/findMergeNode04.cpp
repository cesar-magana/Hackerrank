int countNodes (SinglyLinkedListNode* head) {
    int count = 0;
    while ( head ) {
        count++;
        head = head->next;
    }
    return count;
}

SinglyLinkedListNode* removeFirstKth (SinglyLinkedListNode* head, int k) {
    for (int i = 0; i < k; i++) {
        head = head->next;
    }
    return head;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int count1 = countNodes(head1);
    int count2 = countNodes(head2);
    int skip = abs(count1 - count2);
    if (count1 > count2) head1 = removeFirstKth(head1, skip);
    else head2 = removeFirstKth(head2, skip);
        
    for (int i = 0; i < min(count1, count2); i++) {
        if (head1 == head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}