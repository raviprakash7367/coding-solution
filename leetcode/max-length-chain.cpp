/*
    name= max length chain 
    link- https://practice.geeksforgeeks.org/problems/max-length-chain/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1- greedy;
*/

class Solution{
public:
    
    static bool comp(struct val a, struct val b){
        return a.second < b.second ;
    }
    int maxChainLen(struct val p[],int n){
        sort(p, p+n, comp);
        int count = 1;
        int prev= p[0].second;
        for(int i=1;i<n;i++){
            if(p[i].first > prev){
                count++;
                prev= p[i].second;
            }
        }
        return count;
        
    }
};