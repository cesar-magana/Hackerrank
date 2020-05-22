# Tree : Top View

You are given a pointer to the root of a binary tree. Print the top view of the binary tree.
Top view means when you look the tree from the top the nodes, what you will see will be called the top view of the tree. See the example below.
You only have to complete the function.
For example :

```
   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
```

Top View : 1 -> 2 -> 5 -> 6

**Input Format**

You are given a function,

```
void topView(node * root) {

}
```

**Constraints**
$$
1 \leq \text{Nodes in the tree} \leq 500
$$
**Output Format**

Print the values on a single line separated by space.

**Sample Input**

```
   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
```

**Sample Output**

1 2 5 6

**Explanation**

```
   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
```

From the top only nodes 1,2,5,6 will be visible.



# Solution

These solutions depends on the definition of top view.

#### Approach 1

```c++
void topView(Node * root) {
    stack<int> stk;
    stk.push( root->data );
    Node* current = root;
    while ( root->left ) {
        stk.push( root->left->data );
        root = root->left;
    }
    while ( !stk.empty() ) {
        cout << stk.top() << " ";
        stk.pop();
    }
    while ( current->right ) {
        cout << current->right->data << " ";
        current = current->right;
    }
}
```



#### Approach 2

```c++
void leftView(Node* node) {
    if( node ) {
        leftView( node->left );
        cout << node->data << " ";
    }
}
void rightView(Node* node) {
    if ( node ) {
        cout << node->data << " ";
        rightView( node->right );
    }
}
void topView(Node * root) {
    leftView(root);
    rightView(root->right);
}
```

