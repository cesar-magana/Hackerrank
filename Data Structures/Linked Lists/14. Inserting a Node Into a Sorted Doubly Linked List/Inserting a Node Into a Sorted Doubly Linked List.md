# Inserting a Node Into a Sorted Doubly Linked List

Given a reference to the head of a doubly-linked list and an integer, *data*, create a new *DoublyLinkedListNode* object having data value *data* and insert it into a sorted linked list while maintaining the sort.

**Function Description**

Complete the *sortedInsert* function in the editor below. It must return a reference to the head of your modified DoublyLinkedList.

sortedInsert has two parameters:

1. *head*: A reference to the head of a doubly-linked list of *DoublyLinkedListNode* objects.
2. *data*: An integer denoting the value of *data* the field for the *DoublyLinkedListNode* you must insert into the list.

**Note:** Recall that an empty list (i.e., where head=NULL ) and a list with one element *are* sorted lists.

**Input Format**

The first line contains an integer t, the number of test cases.

Each of the test case is in the following format:

- The first line contains an integer n, the number of elements in the linked list.
- Each of the next n lines contains an integer, the *data* for each node of the linked list.
- The last line contains an integer data which needs to be inserted into the sorted doubly-linked list.

**Constraints**

- $1 \leq t \leq 10$
- $1 \leq n \leq 1000$
- $1 \leq doublelinkedlistnode.data \leq 1000$

**Output Format**

**Do not print anything to stdout.** Your method must return a reference to the *head* of the same list that was passed to it as a parameter.

The ouput is handled by the code in the editor and is as follows:
For each test case, print the elements of the sorted doubly-linked list separated by spaces on a new line.

**Sample Input**

```
1
4
1
3
4
10
5
```

**Sample Output**

```
1 3 4 5 10
```

**Explanation**

The initial doubly linked list is: 1 3 4 10 NULL

The doubly linked list after insertion is: 1 3 4 5 10 NULL

Source: https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem



# Solution

```c++
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    if ( head == NULL ) {
        return newNode;
    }
    else if ( head->data >= data ) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    } else {
        head->next = sortedInsert(head->next, data);
        head->next->prev = head;
    }
    return head;
}
```

