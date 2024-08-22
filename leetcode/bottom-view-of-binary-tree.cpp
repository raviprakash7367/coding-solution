/*
    name= bottom view of binary tree
    link- https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1; 
*/

class Solution {
  public:
    
    void bfs(map<int,int>&m, queue<pair<Node*,int>>&q){
        if(q.empty())return;
        
        int l= q.front().second;
        Node* node= q.front().first;
        
        m[l]= node->data;
        if(node->left) q.push({node->left, l-1});
        if(node->right) q.push({node->right,l+1});
        q.pop();
        bfs(m,q);
        
    }
  
    vector <int> bottomView(Node *root) {
        if(!root) return{};
        map<int,int>m;
        vector<int>bottomViewTree;
        queue<pair<Node*, int>>q;
        q.push({root,0});
        bfs(m,q);
        for(auto mp:m){
            bottomViewTree.push_back(mp.second);
        }
        return bottomViewTree;
    }
};