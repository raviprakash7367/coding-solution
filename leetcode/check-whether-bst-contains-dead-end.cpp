/*
    name=  Check whether BST contains Dead End
    link- https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

void traverse(Node *root, unordered_map<int,int>&m){
    if(!root) return;
    traverse(root->left,m);
    m[root->data]=1;
    traverse(root->right,m);
}

bool check(Node *root,unordered_map<int,int>&m){
    if(!root) return true;
    
    if(!root->left && !root->right){
        if(root->data ==1 && m[2]==1) return false;
        else if(m[root->data -1] == 1 && m[root->data +1]==1) return false;
    }
    bool flag1= check(root->left,m);
    bool flag2= check(root->right,m);
    return flag1 & flag2;
}

bool isDeadEnd(Node *root)
{
    unordered_map<int,int>m;
    traverse(root,m);
    return !check(root,m);
    
}