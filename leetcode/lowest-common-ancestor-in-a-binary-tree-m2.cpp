/*
    name= lowest common ancestor in a binary tree
    link- https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution
{
    public:
    Node * dfs( Node * root, int n1,int n2){
        if(!root) return NULL;
        
        if(root->data== n1 || root->data==n2){
            return root;
        }
        Node *l= dfs(root->left, n1,n2);
        Node *r= dfs(root->right,n1,n2);
        
        if(l && r) return root;
        
        if(l!= NULL) return l;
        else return r;
        
        
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
      
       return dfs(root, n1,n2);
       
    }
};