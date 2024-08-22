/*
    name= Minimum BST Sum Subtree
    link- https://practice.geeksforgeeks.org/problems/d064cc0468a5c2bb7817ecd7c1bc59ce25e23613/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(height of tree) -> for stack
    method 1- recursion;
*/

class Solution {
public:
    // isBST return a vector = {flag, max, min , sum, length} flag tells if the subtree is BST or not
    vector<int>isBST(Node *root, int target, int &ans){
        if(!root->left && !root->right){
            if(root->data == target){
                ans= 1;
            }
            return {1,root->data, root->data, root->data,1};
        }
        else if(!root->left){
            //only right part
            vector<int>right= isBST(root->right, target,ans);
            if(right[0]==1){
                if(root->data < right[2]){
                    // subtree with temparay root as current root is BST
                    int sum= root->data + right[3];
                    int mini= root->data;
                    int maxi= right[1];
                    if(sum == target) {
                        ans= min(ans, right[4]+1);
                    }
                    return {1,maxi,mini,sum,right[4]+1};
                }
                else{
                    return {0,0,0,0,0};
                }
            }
            else{
                return {0,0,0,0,0};
            }
            
        }
        else if(!root->right){
            vector<int>left= isBST(root->left, target,ans);
            if(left[0]==1){
                if(root->data > left[1]){
                    // subtree with temparay root as current root is BST
                    int sum= root->data + left[3];
                    int mini= left[2];
                    int maxi= root->data;
                    if(sum == target) {
                        ans= min(ans, left[4]+1);
                    }
                    return {1,maxi,mini,sum,left[4]+1};
                }
                else{
                    return {0,0,0,0,0};
                }
            }
            else{
                return {0,0,0,0,0};
            }
        }
        else{
             vector<int>left= isBST(root->left, target,ans);
             vector<int>right= isBST(root->right, target,ans);
             if(left[0] && right[0]){
                 if(root->data > left[1] && root->data < right[2]){
                     int sum= root->data + left[3]+right[3];
                     int mini = left[2];
                     int maxi = right[1];
                     int len = left[4]+right[4]+1; 
                     if(sum== target){
                         ans= min(ans, len);
                     }
                     return {1,maxi,mini,sum,len};
                 }
                 else return {0,0,0,0,0};
             }
             else{
                 return {0,0,0,0,0};
             }
        }
        
        return {0,0,0,0,0};
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        int ans= INT_MAX;
        vector<int>temp = isBST(root, target, ans);
        if(ans== INT_MAX){
            return -1;
        }
        else return ans;
    }
};