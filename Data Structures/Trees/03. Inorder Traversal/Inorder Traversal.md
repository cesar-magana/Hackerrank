# Tree: Inorder Traversal

Complete the *inOrder* function in your editor below, which has 1 parameter: a pointer to the root of a binary tree. It must print the values in the tree's inorder traversal as a single line of space-separated values.

**Input Format**

Our hidden tester code passes the root node of a binary tree to your *postOrder* function.

**Constraints**
$$
1 \leq \text{Nodes in the tree} \leq 500
$$
**Output Format**

Print the tree's postorder traversal as a single line of space-separated values.

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
1 2 3 4 5 6 
```

Source: https://www.hackerrank.com/challenges/tree-inorder-traversal/problem

# Solution

#### Recursive approach

```c++
void inOrder(Node *root) {
    if ( root ) {
        inOrder( root->left );
        cout << root->data << " ";
        inOrder( root->right );
    }
}
```

#### Iterative approach

```c++
void inOrder(Node *root) {
    if( !root )
        return;

    stack<Node*> stk;
    Node* current = root;

    while( !stk.empty() || current ){
        if( current ) {
            stk.push( current );
            current = current->left;
        }
        else {
            Node* node = stk.top();
            stk.pop();
            cout << node->data << " ";
            current = node->right;
        }
    }
}
```

