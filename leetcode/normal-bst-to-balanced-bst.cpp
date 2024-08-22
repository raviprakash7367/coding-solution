/*
    name= normal bst to balanced bst
    link- https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

void inorder(Node* root, vector<Node*>&v){
    if(!root) return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right,v);
}

Node *makeBBST(vector<Node *>&v, int l, int r){
    if(l>r) return NULL;
    int mid = (l+r)/2;
    
    Node *root= v[mid];
    root->left= makeBBST(v,l,mid-1);
    root->right= makeBBST(v,mid+1,r);
    return root;
}

Node* buildBalancedTree(Node* root)
{
	if(!root) return NULL;
	vector<Node*>v;
	inorder(root,v);
	root= makeBBST(v,0,v.size()-1);
	return root;
	
}