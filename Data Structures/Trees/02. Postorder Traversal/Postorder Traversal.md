# Tree: Postorder Traversal

Complete the *postOrder* function in your editor below, which has 1 parameter: a pointer to the root of a binary tree. It must print the values in the tree's postorder traversal as a single line of space-separated values.

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
4 3 6 5 2 1 
```

Source: https://www.hackerrank.com/challenges/tree-postorder-traversal/problem



# Solution

#### Recursive approach

```c++
void postOrder(Node *root) {
    if ( root ) {
        postOrder( root->left );
        postOrder( root->right );
        cout << root->data << " ";
    }
}
```

#### Iterative approach

```c++
void postOrder(Node *root) {
    stack<Node*> stk;
    Node* current = root;  

    while( true ) {  
        if( current ) {  
            if( current->right )   
                stk.push( current->right );  
            stk.push( current );  
            current = current->left;  
            continue;  
        }  
        if( stk.empty( ) )   
            return;  
        current = stk.top();
        stk.pop();  

        if( current->right && ! stk.empty() && current->right == stk.top() ) {  
            stk.top();
            stk.pop();
            stk.push( current );  
            current = current->right;  
        } else {  
            cout << current->data << " ";  
            current = NULL;  
        }  
    }
}
```

