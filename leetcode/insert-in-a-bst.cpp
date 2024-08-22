/*
    name= insert in a binary search tree
    link- https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(logn)
    method 1;
*/

Node* insert(Node* root, int key) {
    if(!root) {
        return new Node(key);
    }
    
    if(root->data== key) return root;
    else if( key < root->data) root->left= insert(root->left,key);
    else root->right=insert(root->right, key);
    return root;
}