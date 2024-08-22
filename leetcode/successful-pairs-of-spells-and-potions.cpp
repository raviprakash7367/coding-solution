/*
    name= Successful Pairs of Spells and Potions
    link-  https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
    author- Parth garg
    time complexity- o(n*log m )
    space complexity- o(n)
    method 1- binary search;
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size();
        int m= potions.size();
        sort(potions.begin(),potions.end());
        vector<int>res(n);
        for(int i=0;i<n;i++){
            long long x= success/spells[i];
            if((success%spells[i]) !=0) x++;
            int l=0,r= m-1;
            while(l<r){
                int mid = l+ (r-l)/2;
                if(potions[mid]< x){
                    l= mid+1;
                }
                else{
                    r = mid;
                }
            }
            if(potions[l] < x)res[i]= 0;
            else res[i] = m-l;
        }
        return res;
    }
};