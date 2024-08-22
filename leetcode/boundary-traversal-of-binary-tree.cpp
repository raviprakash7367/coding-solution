/*
    name= boundary traversal of binary tree
    link- https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1; 
*/


class Solution {
public:
    
    void leftSide(Node* node, vector<int>&boundary){
        if(node== NULL) return;
        
        Node *curr= node->left;
        while(curr){
            if(curr->left != NULL || curr->right != NULL){
                boundary.push_back(curr->data);
            }
            if(curr->left) curr= curr->left;
            else curr= curr->right;
        }
    }
    void dfs(Node* node,vector<int>&boundary){
        if(node== NULL) return;
        
        if(node->left== NULL && node->right== NULL) {
            boundary.push_back(node->data);
            return;
        }
        dfs(node->left,boundary);
        dfs(node->right, boundary);
        
    }
    
    void rightside(Node* node, vector<int>&boundary){
        stack<int>s;
        Node *curr= node->right;
        while(curr){
            if(curr->left != NULL || curr->right != NULL) s.push(curr->data);
            if(curr->right) curr= curr->right;
            else curr= curr->left;
        }
        
        while(!s.empty()){
            boundary.push_back(s.top());
            s.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        if(!root) return {};
        vector<int>boundary;
        if(root->left != NULL || root->right != NULL) boundary.push_back(root->data);
        leftSide(root,boundary);
        dfs(root,boundary);
        rightside(root, boundary);
        return boundary;
        
    }
};