# Find Merge Point of Two Lists

Given pointers to the head nodes of 2 linked lists that merge together at some point, find the Node where the two lists merge. It is guaranteed that the two head Nodes will be different, and neither will be NULL.

In the diagram below, the two lists converge at Node `x`:

```
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
```

Complete the `int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)` method so that it finds and returns the data value of the Node where the two lists merge.

**Input Format**

*Do not read any input from stdin/console.*

The `findMergeNode(SinglyLinkedListNode,SinglyLinkedListNode)` method has two parameters, head1and head2, which are the non-null head Nodes of two separate linked lists that are guaranteed to converge.

**Constraints**

The lists will merge.
head1,head2 \neq NULL
head1 \neq head2

**Output Format**

*Do not write any output to stdout/console.*

Each Node has a data field containing an integer. Return the integer data for the Node where the two lists merge.

**Sample Input**

The diagrams below are graphical representations of the lists that input Nodes headA and headB are connected to. Recall that this is a method-only challenge; the method only has initial visibility to those 2 Nodes and must explore the rest of the Nodes using some algorithm of your own design.

**Test Case 0**

```
 1
  \
   2--->3--->NULL
  /
 1
```

**Test Case 1**

```
1--->2
      \
       3--->Null
      /
     1
```

**Sample Output**

```
2
3
```

**Explanation**

*Test Case 0:* As demonstrated in the diagram above, the merge Node's data field contains the integer 2.
*Test Case 1:* As demonstrated in the diagram above, the merge Node's data field contains the integer 3.

Source: hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem



# Solution

#### Approach 1

```c++
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    unordered_set<SinglyLinkedListNode*> set;
    while ( head1 ) {
        set.insert( head1 );
        head1 = head1->next;
    }
    while ( head2 ) {
        if ( set.count( head2 ) )
            break;
        head2 = head2->next;
    }
    return head2->data;
}
```

#### Approach 2

```c++
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
```

#### Approach 3

```c++
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
```

#### Approach 4

```c++
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
```

