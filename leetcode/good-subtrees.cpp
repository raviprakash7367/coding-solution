/*
    name= good subtrees
    link- https://practice.geeksforgeeks.org/problems/df12afc57250e7f6fc101aa9c272343184fe9859/1
    author- Parth garg
    time complexity- o(n*k)
    space complexity- o(n+ n*k)
    method 1;
*/
class Solution{
public:
    int dfs(set<int>&s, Node *root, int k){
        if(!root) return 0;
        set<int>sLeft,sRight;
        int l = dfs(sLeft,root->left, k);
        int r = dfs(sRight,root->right,k);
        
        for(auto it: sLeft){
            s.insert(it);
        }
        for(auto it: sRight){
            s.insert(it);
        }
        s.insert(root->data);
        sLeft.clear();
        sRight.clear();
        if(s.size()<= k)return 1+l+r;
        else return l+r;
    }
    
    int goodSubtrees(Node *root,int k){
        set<int>s;
        return dfs(s,root,k);
    }
};