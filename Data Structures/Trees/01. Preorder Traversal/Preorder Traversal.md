# Tree: Preorder Traversal

Complete the *preOrder* function in your editor below, which has 1 parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

**Input Format**

Our hidden tester code passes the root node of a binary tree to your *preOrder* function.

**Constraints**
$$
1 \leq \text{Nodes in the tree} \leq 500
$$
**Output Format**

Print the tree's preorder traversal as a single line of space-separated values.

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

```
1 2 5 3 4 6 
```

Source: https://www.hackerrank.com/challenges/tree-preorder-traversal/problem



# Solution

#### Approach 1

```c++
void preOrder(Node *root) {
    if ( root ) {
        cout << root->data << " ";
        preOrder( root->left );
        preOrder( root->right );
    }
}
```

#### Approach 2

```c++
void preOrder(Node *root) {
    if ( !root )
        return;
    stack <Node*> stk;
    stk.push( root );
    while ( stk.empty() == false ) {
        Node* node = stk.top();
        stk.pop();
        cout << node->data << " ";
        if ( node->right )
            stk.push( node->right );
        if ( node->left )
            stk.push( node->left );
    }
}
```

