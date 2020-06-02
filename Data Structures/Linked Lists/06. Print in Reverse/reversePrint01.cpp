void reversePrint(SinglyLinkedListNode* head) {
    stack<int> stk;
    while ( head ) {
        stk.push( head->data );
        head = head->next;  
    }
    while ( !stk.empty() ) {
        cout << stk.top() << endl;
        stk.pop();
    }
}