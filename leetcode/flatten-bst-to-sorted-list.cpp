/*
    name= Flatten BST to sorted list 
    link-  https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/


// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL)
		cout << curr->data << " ", curr = curr->right;
}
node* head;
void inorder(node * root, node *&prev){
    if(!root) return;
    inorder(root->left, prev);
    if(prev== NULL){
        prev= root;
        head= root;
    }
    else{
        prev->left= NULL;
        prev->right= root;
        prev= root;
    }
    inorder(root->right,prev);
}


int main()
{
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	// Calling required function
    node *prev= NULL;
    inorder(root,prev);
    prev->left= NULL;
    prev->right=NULL;
	print(head);
	return 0;
}
