# Get Node Value

You’re given the pointer to the head node of a linked list and a specific position. Counting backwards from the tail node of the linked list, get the value of the node at the given position. A position of 0 corresponds to the tail, 1 corresponds to the node before the tail and so on.

**Input Format**

You have to complete the `int getNode(SinglyLinkedListNode* head, int positionFromTail)` method which takes two arguments - the head of the linked list and the position of the node from the tail. positionFromTail will be at least 0 and less than the number of nodes in the list. You should NOT read any input from stdin/console.

The first line contains an integer t, denoting the number of test cases.
Each test case has the following format:

The first line contains an integer n, the number of elements in the linked list.
The next n lines contains, an element each denoting the element of the linked list.
The last line contains an integer positionFromTail denoting the position from the tail, whose value needs to be found out and returned.

**Constraints**

- $1 \leq t \leq 10$
- $1 \leq n \leq 1000$
- $1 \leq list_i \leq 1000$, where is list_i the i th element in the list.
- $0 \leq positionFromTail<n$

**Output Format**

Find the node at the given position counting backwards from the tail. Then `return` the `data` contained in this node. Do NOT print anything to stdout/console.

The code in the editor handles output.
For each test case, print the value of the node, each in a new line.

**Sample Input**

```
2
1
1
0
3
3
2
1
2
```

**Sample Output**

```
1
3
```

**Explanation**

In first case, there is one element in linked list with value 1. Hence, last element is 1.

In second case, there are 3 elements with values 3, 2 and 1 (3 -> 2 -> 1). Hence, element with position of 2 from tail is 3.

# Solution

#### Approach 1

```c++
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    stack<int> stk;
    
    SinglyLinkedListNode* current = head;
    while ( head ) {
        stk.push( head->data );
        head = head->next;
    }
    for ( int i = 0; i < positionFromTail; i++ ) {
        stk.pop();
    }
    return stk.top();
}
```

#### Approach 2

```c++
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* current = head;
    int count = 0;
    while ( head ) {
        count++;
        head = head->next;
    }
    for ( int i = 0; i < count-positionFromTail-1; i++ ) {
        current = current->next;
    }
    return current->data;
}
```

#### Approach 3

```c++
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* node = head;
    for (int i = 0; i < positionFromTail+1; i++) {
        head = head->next;
    }
    while ( head ) {
        head = head->next;
        node = node->next;
    }
    return node->data;    
}
```

#### Approach 4

```c++
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int i = 0;
    SinglyLinkedListNode* result = head;
    SinglyLinkedListNode* curr = head;
    while ( curr ) {
        curr = curr->next;
        if ( i++ > positionFromTail ) {
            result = result->next;
        }
    }
    return result->data;   
}
```

#### Approach 5

```c++
int getLength(SinglyLinkedListNode* head) {
    if ( head == NULL ) return 0;
    return 1 + getLength(head->next);
}
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int length = getLength(head);
    for (int i = 0; i < length - positionFromTail - 1; i++) {
        head = head->next;
    }
    return head->data;
}
```

