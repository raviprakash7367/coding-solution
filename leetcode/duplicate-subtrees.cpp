
/*
    name= duplicate subtrees
    link- https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1;
*/

string subTreesFreq(Node *root,unordered_map<string,pair<Node*,int>>&m){
    if(!root) return "$";
    if(root->left== NULL && root->right== NULL){
        string s= "$"+to_string(root->data);
        m[s].first= root;
        m[s].second= m[s].second+1;
        return s;
    }
    string s= to_string(root->data) + subTreesFreq(root->left,m) + subTreesFreq(root->right,m);
    m[s].first= root;
    m[s].second= m[s].second+1;
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    unordered_map<string,pair<Node*,int>>m;
    vector<Node *> res;
    subTreesFreq(root,m);
    for(auto mp :m){
        if(mp.second.second > 1)res.push_back(mp.second.first);
    }
    return res;
}