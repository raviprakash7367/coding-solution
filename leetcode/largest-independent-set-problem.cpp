/*
    name= Largest Independent Set Problem
    link- https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

map<Node *, int> dp;
int solve(Node *root){
    if(root == NULL) return 0;
    
    if(dp[root] != 0) return dp[root];
    
    int take= 1+ ((root->left != NULL)?(solve(root->left->left)+solve(root->left->right)):0 );
    take+= ((root->right!= NULL)?(solve(root->right->left)+solve(root->right->right)):0 );
    
    int notTake= solve(root->left)+ solve(root->right);
    
    return dp[root] = max(take, notTake);
}

int LISS(Node *root)
{
    return solve(root);
}