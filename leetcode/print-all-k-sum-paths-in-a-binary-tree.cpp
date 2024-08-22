/*
    name= print k sum paths binary tre e
    link- https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
    author- Parth garg
    time complexity- o(n*h)
    space complexity- o(h)-> extra space  o(h*h)->for storing result
    method 1;
*/

#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<vector<int>>res;
void findKSum(Node *root,int k,vector<int>&path){
    if(!root) return ;
    
    path.push_back(root->data);

    findKSum(root->left,k,path);
    findKSum(root->right,k,path);

    int p=0;
    vector<int>temp;
    for(int i=path.size()-1; i>=0;i--){
        p+= path[i];
        temp.push_back(path[i]);
        if(p==k){
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
    }
    temp.clear();
    path.pop_back();
}

void printKPath(Node* root, int k){
    if(!root) return ;
    vector<int>path;
    findKSum(root,k,path);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<< res[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
  
    int k = 5;
    printKPath(root, k);
  
    return 0;
}