# Is This a Binary Search Tree?

For the purposes of this challenge, we define a [binary tree](https://en.wikipedia.org/wiki/Binary_tree) to be a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) with the following ordering requirements:

- The value of every node in a node's left subtree is *less than* the data value of that node.
- The value of every node in a node's right subtree is *greater than* the data value of that node.

Given the root node of a binary tree, can you determine if it's also a binary search tree?

Complete the function in your editor below, which has parameter: a pointer to the root of a binary tree. It must return a *boolean* denoting whether or not the binary tree is a binary search tree. You may have to write one or more helper functions to complete this challenge.

**Input Format**

You are not responsible for reading any input from stdin. Hidden code stubs will assemble a binary tree and pass its root node to your function as an argument.

**Constraints**
$$
0 \leq data \leq 10^4
$$


**Output Format**

You are not responsible for printing any output to stdout. Your function must return *true* if the tree is a binary search tree; otherwise, it must return *false*. Hidden code stubs will print this result as a *Yes* or *No* answer on a new line.

**Sample Input**

![tree](https://s3.amazonaws.com/hr-challenge-images/8131/1461698192-c9e0fcb28d-BTinput.png)

**Sample Output**

```
No
```



# Solution

```c++
bool checkBST(Node* root, int min, int max) {
    if ( !root ) 
        return true;
    if ( root->data < min || root->data > max )
        return false;
    return 	checkBST( root->left, min, root->data-1 ) && 
       		checkBST( root->right, root->data+1, max );
}

bool checkBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}
```

