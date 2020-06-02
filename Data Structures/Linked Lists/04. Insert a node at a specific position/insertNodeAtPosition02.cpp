SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* node = head;
    if (position == 0){
        node = new SinglyLinkedListNode(data);
        node->next = head;
        return node;
    }
    else {
        while(--position > 0){
            node = node->next;
        }
        SinglyLinkedListNode* insert = node->next;
        node->next = new SinglyLinkedListNode(data);
        node->next->data = data;
        node->next->next = insert;
        return head;
    }
}