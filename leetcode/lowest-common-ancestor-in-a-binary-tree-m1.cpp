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
    void dfs( Node * root, int n1,int n2, vector<Node *>&path, vector<vector<Node *>>&v){
        if(!root) return;
        path.push_back(root);
        if(root->data== n1 || root->data==n2){
            v.push_back(path);
        }
        dfs(root->left, n1,n2,path,v);
        dfs(root->right,n1,n2,path,v);
        path.pop_back();
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<Node*>path;
       vector<vector<Node *>> v;
       dfs(root, n1,n2,path,v);
       if(v.size()==0) return NULL;
       else{
           Node * node= NULL;
           int n= min(v[0].size(),v[1].size());
           for(int i=0;i<n;i++){
               if(v[0][i]->data== v[1][i]->data) node= v[0][i];
               else break;
           }
           return node;
       }
       
    }
};