
/*
    name= Diagonal Traversal of Binary Tree
    link- https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

void traverseDiagonally(Node *node, int x,int y,map<int,vector<int>>&m){
    if(!node) return;
    int z= abs(x-y);
    m[z].push_back(node->data);
    traverseDiagonally(node->left,x-1,y+1,m);
    traverseDiagonally(node->right,x+1,y+1,m);
}

vector<int> diagonal(Node *root)
{
    map<int, vector<int>>m;
    vector<int>diagonalTree;
    traverseDiagonally(root,0,0,m);
    for (auto mp:m){
        for(auto val:mp.second){
            diagonalTree.push_back(val);
        }
    }
    return diagonalTree;
    