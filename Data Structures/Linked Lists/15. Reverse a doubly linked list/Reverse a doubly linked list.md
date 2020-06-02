# Reverse a doubly linked list

You’re given the pointer to the head node of a doubly linked list. Reverse the order of the nodes in the list. The head node might be NULL to indicate that the list is empty. Change the *next* and *prev* pointers of all the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list.

**Function Description**

Complete the *reverse* function in the editor below. It should return a reference to the head of your reversed list.

reverse has the following parameter(s):

- *head*: a reference to the head of a DoublyLinkedList

**Input Format**

The first line contains an integer , the number of test cases.

Each test case is of the following format:

- The first line contains an integer t, the number of elements in the linked list.
- The next lines contain an integer n each denoting an element of the linked list.

**Constraints**

- $1 \leq t \leq 10$
- $1 \leq n \leq 1000$
- $1 \leq doublelinkedlistnode.data \leq 1000$

**Output Format**

Return a reference to the head of your reversed list. The provided code will print the reverse array as a one line of space-separated integers for each test case.

**Sample Input**

```
1
4
1
2
3
4
```

**Sample Output**

```
4 3 2 1 
```

**Explanation**

The initial doubly linked list is: 1 2 3 4 NULL

The reversed doubly linked list is: 4 3 2 1 NULL

Source: https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem



# Solution

#### Approach 1

```c++
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if ( head == NULL || head->next == NULL )
        return head;
    DoublyLinkedListNode* current = head;
    DoublyLinkedListNode* previous = NULL;
    DoublyLinkedListNode* next = NULL;

    while ( current ) {
        next = current->next;
        current->next = previous;
        current->prev = next;
        previous = current;
        current = next;
    }
    return previous;
}
```

#### Approach 2

```c++
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    // If head is NULL or only one node, it's reverse of itself.
    if ( head == NULL || head->next == NULL )
        return head;
    // Reverse the sub-list leaving the head node.
    DoublyLinkedListNode* temp = reverse(head->next);
    // head->next still points to the last element of reversed sub-list.
    // Move the head to the end.
    head->next->next = head;
    // Point the last node to NULL, get rid of cycles.
    head->next = NULL;
    return temp;
}
```

