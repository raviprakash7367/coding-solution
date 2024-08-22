/*
    name= permutation sequence
    link- https://leetcode.com/problems/permutation-sequence/description/
    author- Parth garg
    time complexity- o(n*n);
    space complexity- o(n)
    method 1;
*/

class Solution {
public:

    string getPermutation(int n, int k) {
        vector<int>v;
        int fact= 1;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
            fact= fact*i;
        }
        fact= fact/n;
        k--;
        string ans="";
        while(true)
        {
            int x= k/fact;
            ans+= ('0'+ v[x]);
            v.erase(v.begin()+ (k/fact));
            if(ans.size()==n)break;
            k= k% fact;
            fact= fact/v.size();
          
        }
        return ans;

    }
};