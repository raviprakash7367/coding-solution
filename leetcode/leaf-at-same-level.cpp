/*
    name= leaf at same level
    link- https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1; 
*/


class Solution{
  public:
    bool ans;
    bool dfs(Node *root, int *leafLevel,int level){
        if(root== NULL) return true;
        
        if(root->left ==NULL && root->right ==NULL){
            if(*leafLevel== -1) *leafLevel= level;
            else{
                if(*leafLevel != level) {
                    return false;
                }
                else return true;
            }
        }
        return dfs(root->left, leafLevel, level+1) && dfs(root->right, leafLevel, level+1);
        
    }
    
    bool check(Node *root)
    {
        
        int leafLevel= -1;
        return dfs(root, &leafLevel, 0);;
    }
};