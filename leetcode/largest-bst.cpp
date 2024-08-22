/*
    name= largest bst
    link- https://practice.geeksforgeeks.org/problems/largest-bst/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(height of tree)
    method 1;
*/

class Solution{
    public:
    
    class info{
        public:
        int max;
        int min;
        bool isBST;
        int size;
    };
    info findMaxCount(Node *root,int &ans){
        if(!root){
            return {INT_MIN, INT_MAX, true,0};
        }
        
        info left= findMaxCount(root->left,ans);
        info right= findMaxCount(root->right,ans);
        
        info currNode;
        currNode.size= left.size +right.size +1;
        currNode.min= min(root->data,left.min);
        currNode.max= max(root->data,right.max);
        if(left.isBST && right.isBST && root->data > left.max && root->data < right.min){
            currNode.isBST= true;
            ans= max(ans, currNode.size);
        }
        else{
            currNode.isBST= false;
        }
        
        return currNode;
    }
    
    int largestBst(Node *root)
    {
    	int ans=0;
    	info solve= findMaxCount(root, ans);
    	return ans;
    }
};