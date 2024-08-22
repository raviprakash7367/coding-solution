/*
    name= min distance between two given nodes of a binary tree
    link- https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


class Solution{
    public:
    int ans;
    int findlr(Node * root, int n1, int n2){
        if(!root) return 0;
        
        int l= findlr(root->left, n1,n2);
        int r= findlr(root->right,n1,n2);
        
        if(root->data== n1 || root->data== n2){
            ans= max(ans, l+r);
            return l+r+1;
        }
        if((l!=0 && r!=0)) ans= max(ans,l+r);
        
        if(l==0 && r==0) return l+r;
        else return l+r+1;
        
    }
    
    int findDist(Node* root, int a, int b) {
        ans=0;
        findlr(root, a,b);
        return ans;
    }
};