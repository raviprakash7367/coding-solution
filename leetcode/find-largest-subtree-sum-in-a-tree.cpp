/*
    name= find largest subtree sum in a tree
    link- https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h) height of tree
    method 1;
*/

#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};
 
// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
int maxi;
int subTreeSum(Node *root){
    if(!root) return 0;
    int ans= root->key+ subTreeSum(root->left) +subTreeSum(root->right);
    if(ans>maxi) maxi= ans;

    return ans;
}

int findLargestSubtreeSum(Node* root){
    if(!root) return 0;
    maxi= INT_MIN;
    subTreeSum(root);
    return maxi;
}

int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
 
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
 
    cout << findLargestSubtreeSum(root);
    return 0;
}