/*
    name= sum of longest bloodline of a tree
    link- https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution
{
public:
    int ans;
    void rootToLeaf(Node *root, int level, int*maxLevel,int sum){
        if(!root) return;
        
        if(level> *maxLevel) {
            ans= sum+ root->data;
            *maxLevel= level;
        }
        else if(level== *maxLevel){
            ans= max(ans, sum + root->data);
        }
        
        rootToLeaf(root->left, level+1, maxLevel, sum+root->data);
        rootToLeaf(root->right, level+1, maxLevel, sum+root->data);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        ans= INT_MIN;
        int maxLevel=0;
        rootToLeaf(root,0, &maxLevel, 0);
        return ans;
    }
};