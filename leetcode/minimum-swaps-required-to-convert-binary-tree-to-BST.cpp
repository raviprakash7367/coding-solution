/*
    name= minimum swaps required to convert binary tree to binary search tree
    link- https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1- extension of question- minimum swaps needed to sort the array;
*/

class Solution{
  public:
    
    void inorderTraversal(vector<int>&A, vector<int>&v, int idx){
        if(idx >= A.size()) return;
        
        inorderTraversal(A,v, (2*idx) +1);
        
        v.push_back(A[idx]);
        inorderTraversal(A,v, (2*idx) +2);
    }
    
    int minSwaps(vector<int>&v){
        int n= v.size();
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({v[i],i});
        }
        
        sort(temp.begin(),temp.end());
        
        int swaps=0;
        for(int i=0;i<n;i++){
            int value= temp[i].first;
            int index= temp[i].second;
            
            if(i!= index){
                swaps++;
                swap(temp[i],temp[index]);
                i--;
            }
        }
        return swaps;
        
    }
    
    
    int minSwaps(vector<int>&A, int n){
        vector<int>v;
        inorderTraversal(A,v,0);
        return minSwaps(v);
    }
    
    
};