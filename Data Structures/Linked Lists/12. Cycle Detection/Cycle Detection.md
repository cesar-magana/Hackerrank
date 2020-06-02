# Cycle Detection

A linked list is said to contain a *cycle* if any node is visited more than once while traversing the list.

Complete the function provided for you in your editor. It has one parameter: a pointer to a *Node* object named head that points to the head of a linked list. Your function must return a boolean denoting whether or not there is a cycle in the list. If there *is* a cycle, return *true*; otherwise, return *false*.

**Note:** If the list is empty, head will be *null*.

**Input Format**

Our hidden code checker passes the appropriate argument to your function. You are not responsible for reading any input from stdin.

**Constraints**

- $0 \leq list_size \leq 1000$

**Output Format**

If the list contains a cycle, your function must return *true*. If the list *does not* contain a cycle, it must return *false*. The binary integer corresponding to the boolean value returned by your function is printed to stdout by our hidden code checker.

**Sample Input**

The following linked lists are passed as arguments to your function:

![Sample Inputs](https://s3.amazonaws.com/hr-challenge-images/1163/1463778594-900a0ae522-inputs.png)

**Sample Output**

```
0
1
```

**Explanation**

1. The first list has no cycle, so we return *false* and the hidden code checker prints 0 to stdout.
2. The second list has a cycle, so we return *true* and the hidden code checker prints 1 to stdout.



Source: https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem



# Solution

#### Approach 1

```c++
bool has_cycle(SinglyLinkedListNode* head) {
    if ( head == NULL ) return false;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head->next;

    while ( fast && fast->next ) {
        if ( slow == fast ) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
```

```c++
bool has_cycle(SinglyLinkedListNode* head) {
    if ( head == NULL ) return false;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while ( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;
        if ( slow == fast )
            return true;
    }
    return false;
}
```

```c++
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* fast = head;
    
    while( fast && fast->next ) {
        fast = fast->next->next;
        head = head->next;
        if( head == fast )
            return true;
    }
    return false;
}
```

#### Approach 2

```c++
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
```

#### Approach 3

```c++
bool has_cycle(SinglyLinkedListNode* head) {
    if ( head == NULL ) return false;
    int count = 0;
    while ( head ) {
        head = head->next;
        if ( count++ == 1001) 
            return true;
    }
    return false;
}
```

#### Approach 4

```c++
bool hasCycleRecursive(SinglyLinkedListNode* head, unordered_set<SinglyLinkedListNode*> seen) {
    if ( head == NULL ) return false;
    if ( seen.count(head) ) return true;
    seen.insert(head);
    return hasCycleRecursive(head->next, seen);
}

bool has_cycle(SinglyLinkedListNode* head) {
    return hasCycleRecursive(head,unordered_set<SinglyLinkedListNode*>());
}
```

